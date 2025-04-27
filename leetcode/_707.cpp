class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node(int x) : val(x), next(nullptr) {}
    };

    Node *dummy;
    int size;

public:
    MyLinkedList()
    {
        dummy = new Node(0);
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index > size - 1)
            return -1;

        Node *cur = dummy->next;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        // 设置好prev指针的位置
        Node *prev = dummy;
        for (int i = 0; i < index; i++)
        {
            prev = prev->next;
        }

        // 插入节点
        Node *node = new Node(val);
        node->next = prev->next;
        prev->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > size - 1)
            return;

        Node *prev = dummy;

        for (int i = 0; i < index; i++)
        {
            prev = prev->next; // 找到待删除节点的上一个节点
        }

        Node *temp = prev->next;
        prev->next = temp->next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */