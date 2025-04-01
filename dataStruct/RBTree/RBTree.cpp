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

    // // 左旋操作
    // void leftRotate(Node* x) {
    //     Node* y = x->right;
    //     x->right = y->left;
    //     if (y->left != nullptr)
    //         y->left->parent = x;
    //     y->parent = x->parent;
    //     if (x->parent == nullptr) {  // x 为根节点
    //         root = y;
    //     } else if (x == x->parent->left) {
    //         x->parent->left = y;
    //     } else {
    //         x->parent->right = y;
    //     }
    //     y->left = x;
    //     x->parent = y;
    // }

    void leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
}
