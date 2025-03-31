#include <iostream>

using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    /* data */
    int key;
    Color color;
    Node *left, *right, *parent;

    explicit Node(int k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree
{
private:
    Node *root;
    Node *nil;
}
