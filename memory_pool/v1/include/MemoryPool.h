#pragma once
#include <atomic>
#include <mutex>
#include <cassert>
#include <iostream>
namespace lxh_memory_pool
{
#define MEMORY_POOL_NUM 64
#define SLOT_BASE_SIZE 8
#define MAX_SLOT_SIZE 512

    struct Slot
    {
        /* data */
        std::atomic<Slot *> next;
    };

    class MemoryPool
    {
    public:
        MemoryPool(size_t BlockSize = 4096);
        ~MemoryPool();

        void init(size_t);

        void *allocate();
        void deallocate(void *);

    private:
        void allocateNewBlock();
        size_t padPointer(char *p, size_t align);

        /*
        使用CAS操作进行无锁入队和出队
        CAS（Compare And Swap，比较并交换）是一种原子操作，常用于多线程编程中实现无锁数据结构。
        它的基本原理是：比较某个变量的当前值是否等于预期值，如果相等则将其更新为新值，否则不做任何操作。
        */
        bool pushFreeList(Slot *slot);
        Slot *popFreeList();

    private:
        int BlockSize_;                // 内存块的大小
        int SlotSize_;                 // 槽的大小
        Slot *firstBlock_;             // 指向内存池管理的首个实际内存块
        Slot *curSlot_;                // 指向当前未被使用过的槽
        std::atomic<Slot *> freeList_; // 指向当前空闲的槽（指被使用过后又释放的槽）
        Slot *lastSlot_;               // 作为内存块中最好能够存放元素的位置标识
        std::mutex mutexForBlock_;     // 保证多线程情况下避免不必要的重复开辟内存
    };

    /*
    管理内存分配的类，通过静态方法为不同大小内存块提供高效的分配和释放机制。
    */
    class HashBucket
    {
    public:
        static void initMemoryPool();
        static MemoryPool &getMemoryPool(int index);

        static void *useMemory(size_t size)
        {
            if (size <= 0)
                return nullptr;
            if (size > MAX_SLOT_SIZE) // 大于512字节的内存用new

                // operator new 用来分配原始内存，不会调用构造函数
                return operator new(size);

            return getMemoryPool(((size + 7) / SLOT_BASE_SIZE) - 1).allocate();
        }

        static void freeMemory(void *ptr, size_t size)
        {
            if (!ptr)
                return;
            if (size > MAX_SLOT_SIZE)
            {
                operator delete(ptr);
                return;
            }

            getMemoryPool(((size + 7) / SLOT_BASE_SIZE) - 1).deallocate(ptr);
        }

        // 模版
        template <typename T, typename... Args>
        // 友员函数，外部函数访问类的私有变量
        friend T *newElement(Args &&...args);

        template <typename T, typename... Args>
        friend void deleteElement(T *p);
    };
    // TOLEARN
    template <typename T, typename... Args>
    T *newElement(Args &&...args)
    {
        T *p = nullptr;
        // 根据元素大小选择合适的内存池分配
        if ((p = reinterpret_cast<T *>(HashBucket::useMemory(sizeof(T)))) != nullptr)
            // 在分配的内存上构造对象
            new (p) T(std::forward<Args>(args)...);

        return p;
    }

    template <typename T, typename... Args>
    void deleteElement(T *p)
    {
        // 对象析构
        if (p)
        {
            p->~T();
            // 内存回收
            HashBucket::freeMemory(reinterpret_cast<void *>(p), sizeof(T));
        }
    }

}