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
        node->height = max(node->right->height, node->left->height) + 1;
    }

    Node *rotationRight(Node *node)
    {
        Node *temp = node->left;
        Node *temp2 = temp->right;

        temp->right = node;
        node->left = temp->right;

        upDateHeight(temp);
        upDateHeight(node);

        return temp;
    }

    Node *rotationLeft(Node *y)
    {
        Node *x = y->right;
        Node *temp = x->left;

        x->left = y;
        y->right = temp;

        upDateHeight(y);
        upDateHeight(x);

        return x;
    }

    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);

        if (key < node->key)
        {
            insert(node->left, key);
        }
        else if (key > node->key)
        {
            insert(node->right, key);
        }
        else
        {
            return node;
        }

        upDateHeight(node);
        int balance = getBalanceFactor(node);

        // LL
        if (balance > 1 && key < node->left->key)
        {
            return rotationLeft(node);
        }
        // LR
        if (balance > 1 && key > node->left->key)
        {
            node->left = rotationLeft(node->left);
            return rotationRight(node);
        }
        // RR
        if (balance < 1 && key > node->right->key)
        {
            return rotationLeft(node);
        }
        // RL
        if (balance < 1 && key < node->right->key)
        {
            node->right = rotationRight(node->right);
            return rotationLeft(node);
        }
    }
};
