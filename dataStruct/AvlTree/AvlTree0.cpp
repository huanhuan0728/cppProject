#include <iostream>

using namespace std;

class AVLTree0
{
private:
    struct Node
    {
        /* data */
        int key;
        int height;
        Node *left;
        Node *right;
        Node(int k) : key(k), height(0), left(nullptr), right(nullptr) {}
    };

    Node *root;

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void upDateHeight(Node *node)
    {
        }
};
