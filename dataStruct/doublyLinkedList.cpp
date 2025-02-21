#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node *next;
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
    void push_back(int val);
    void insert(int val, int pos);
    void pop_front();
    void pop_back();
    void remove(int pos);
    Node *find(int val);
    void print_front();
    void print_back();
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