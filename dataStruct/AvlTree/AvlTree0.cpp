#include <iostream>

using namespace std;

class AvlTree0
{
private:
    /* data */
    struct Node
    {
        /* data */
        int key;
        int height;
        Node *left;
        Node *right;
        Node(int k) : key(k), height(1), left(nullptr), right(nullptr);
    };

    // public:
    //     AvlTree0(/* args */);
    // ~AvlTree0();
};

AvlTree0::AvlTree0(/* args */)
{
}

AvlTree0::~AvlTree0()
{
}
