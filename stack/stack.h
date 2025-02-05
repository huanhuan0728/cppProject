#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    /* data */
    enum
    {
        MAX = 10
    }; // constant specific to class
    Item items[MAX]; // holds stack items
    int top;         // index for top stack item
public:
    Stack(/* args */);
    // ~Stack();
    bool isempty() const;
    bool isfull() const;
    //  push() returns false if stack already is full, true otherwise
    bool push(const Item &item);
    bool pop(Item &item); // pop top into item
};

// Stack::Stack(/* args */)
// {
// }

// Stack::~Stack()
// {
// }

#endif