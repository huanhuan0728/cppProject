#include <iostream>

using namespace std;

class Avltree
{
private:
    struct Node
    {
        int key;
        int height;
        Node *left;
        Node *right;
        Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
    };

    Node *root;

    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    void updateHeight(Node *node)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    int getBalanceFactor(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;
    }
};