#include "include/MemoryPool.h"

namespace lxh_memory_pool
{
#define MEMORY_POOL_NUm 64
#define SLOT_BASE_SIZE 8
#define MAX_SLOT_SIZE 512
    // 实现构造函数
    MemoryPool::MemoryPool(size_t BlockSize) : BlockSize_(BlockSize), SlotSize_(0), firstBlock_(nullptr), curSlot_(nullptr), freeList_(nullptr), lastSlot_(nullptr) {}
    MemoryPool::~MemoryPool()
    {
        // 删除连续的Slot
        Slot *cur = firstBlock_;
        while (cur)
        {
            Slot *next = cur->next;
            operator delete(reinterpret_cast<void *>(cur));
            cur = next;
        }
    }

    void MemoryPool::init(size_t size)
    {
        assert(size > 0);
        SlotSize_ = size;
        firstBlock_ = nullptr;
        curSlot_ = nullptr;
        freeList_ = nullptr;
        lastSlot_ = nullptr;
    }

    void *MemoryPool::allocate()
    {
        Slot *slot = popFreeList();
        if (slot != nullptr)
            return slot;

        Slot *temp;
        {
            std::lock_guard<std::mutex> lock(mutexForBlock_);
            if (curSlot_ >= lastSlot_)
            {
                // 当前内存块已经无内存槽可以用
                allocateNewBlock();
            }
            temp = curSlot_;
            // 这里不能直接 curSlot_ += SlotSize_ 因为curSlot_是Slot*类型所以需要除以SlotSize_再加1
            curSlot_ += SlotSize_ / sizeof(Slot);
        }

        return temp;
    }

    void MemoryPool::allocateNewBlock()
    {
        std::cout << "申请一块新内存，SlotSize: " << SlotSize_ << std::endl;
        void *newBlock = operator new(BlockSize_);
        reinterpret_cast<Slot *>(newBlock)->next = firstBlock_;
        firstBlock_ = reinterpret_cast<Slot *>(newBlock);

        char *body = reinterpret_cast<char *>(newBlock) + sizeof(Slot *);
        size_t paddingSize = padPointer(body, SlotSize_);
        curSlot_ = reinterpret_cast<Slot *>(body + paddingSize);

        // 超过标记位置，说明内存块已经无内存槽可用，需要向系统申请新内存块
        lastSlot_ = reinterpret_cast<Slot *>(reinterpret_cast<size_t>(newBlock) + BlockSize_ - SlotSize_ + 1);

        freeList_ = nullptr;
    }

    // 让指针对齐槽大小的倍数位置
    size_t MemoryPool::padPointer(char *p, size_t allign)
    {
        // allign是槽的大小
        return (allign - reinterpret_cast<size_t>(p)) % allign;
    }

    // 无锁入队
    bool MemoryPool::pushFreeList(Slot *slot)
    {
        while (true)
        {
            // 获取当前头节点
            Slot *oldHead = freeList_.load(std::memory_order_relaxed);
            // 新节点的next指向当前头节点
            slot->next.store(oldHead, std::memory_order_relaxed);

            // 尝试将新节点设置为头节点
            if (freeList_.compare_exchange_weak(oldHead, slot, std::memory_order_release,
                                                std::memory_order_relaxed))
            {
                return true;
            }

            // 失败，说明另外一个线程已经修改了freeList_
            // 重试
        }
    }

    Slot *MemoryPool::popFreeList()
    {
        while (true)
        {
            /* code */
            Slot *oldHead = freeList_.load(std::memory_order_acquire);
            if (oldHead == nullptr)
            {
                return nullptr; // 队列为空
            }
            Slot *newHead = nullptr;
            try
            {
                newHead = oldHead->next.load(std::memory_order_relaxed);
            }
            catch (...)
            {
                // 如果失败，则continue继续申请内存
            }

            // 尝试更新头结点
            // 原子性地尝试将freeList_从oldHead更新为newHead
            if (freeList_.compare_exchange_weak(oldHead, newHead),
                std::memory_order_acquire, std::memory_order_relaxed)
            {
                return oldHead;
            }

            // 失败：说明另一个线程可能已经修改freeList_
            // CAS 失败重试
        }
    }

    void HashBucket::initMemoryPool()
    {
        for (int i = 0; i < MEMORY_POOL_NUM; i++)
        {
            getMemoryPool(i).init((i + 1) * SLOT_BASE_SIZE);
        }
    }

    // 单例模式
    MemoryPool &HashBucket::getMemoryPool(int index)
    {
        static MemoryPool memoryPool[MEMORY_POOL_NUM];
        return memoryPool[index];
    }
}