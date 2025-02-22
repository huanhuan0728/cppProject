#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();

    void insert_front(int val);
    void push_front(int val);
    void push_back(int val);
    void insert(int val, int pos);
    void pop_front();
    void pop_back();
    void remove(int val);
    Node *find(int val);
    void print_forward();
    void print_backward();
};

DoublyLinkedList::~DoublyLinkedList()
{
    Node *temp = head;
    while (temp)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
}

void DoublyLinkedList::insert_front(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::push_front(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::push_back(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::insert(int val, int pos)
{
    if (pos <= 0)
    {
        insert_front(val);
        return;
    }

    Node *current = head;
    for (int i = 0; i < pos - 1 && current; i++)
    {
        current = current->next;
    }

    if (!current)
    {
        push_back(val);
        return;
    }

    Node *newNode = new Node(val);
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void DoublyLinkedList::pop_front()
{
    if (!head)
    {
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::pop_back()
{
    if (!tail)
    {
        return;
    }

    Node *temp = tail;
    tail = tail->prev;
    if (tail)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::remove(int val)
{
    Node *current = head;
    while (current)
    {
        if (current->data == val)
        {
            if (current->prev)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }

            if (current->next)
            {
                current->next->prev = current->prev;
            }
            else
            {
                tail = current->prev;
            }
        }

        current = current->next;
    }
}

Node *DoublyLinkedList::find(int val)
{
    Node *current = head;
    while (current)
    {
        if (current->data == val)
        {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void DoublyLinkedList::print_forward()
{
    Node *current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_backward()
{
    Node *current = tail;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

int main()
{
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.print_forward();
    dll.pop_front();
    dll.print_forward();
    dll.push_front(0);
    dll.print_forward();
    dll.pop_back();
    dll.print_forward();
    dll.insert(4, 1);
    dll.print_forward();
    dll.remove(2);
    dll.print_forward();
    return 0;
}