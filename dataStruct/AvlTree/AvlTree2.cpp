#include <iostream>
using namespace std;

class AvlTree
{
public:
    AvlTree() : root(nullptr) {}
    ~AvlTree()
    {
        destroyRecursive(root);
    }

private:
    struct Node
    {
        int key;
        Node *left;
        Node *right;
        int height;
        Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
    };

    Node *root; // 这里为什么要设一个root

    void destroyRecursive(Node *node)
    {
        if (node)
        {
            destroyRecursive(node->left);
            destroyRecursive(node->right);
            delete node;
        }
    }

    // 获取高度
    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    // 获取平衡因子
    int getBalanceFactor(Node *node)
    {
        return node ? node->left->height - node->right->height : 0;
    }

    // 更新高度
    void updateHeight(Node *node)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    // 右旋
    Node *rotationRight(Node *node)
    {
        Node *x = node->left;
        Node *T2 = x->right;

        x->right = node;
        node->left = T2;

        updateHeight(node);
        updateHeight(x);

        return x;
    }

    // 左旋
    Node *rotationLeft(Node *node)
    {
        Node *x = node->right;
        Node *T2 = x->left;

        x->left = node->right;
        node->right = T2;

        updateHeight(node);
        updateHeight(x);

        return x;
    }

    Node *insert(Node *node, int val)
    {
        if (!node)
        {
            return new Node(val);
        }

        //  节点插入的位置
        if (val < node->key)
            node->left = insert(node->left, val);
        else if (val > node->key)
            node->right = insert(node->right, val);
        else
            return node;

        // 更新高度
        updateHeight(node);

        // 获取平衡因子
        int balance = getBalanceFactor(node);

        // LL case
        if (balance > 1 && val < node->left->key)
            return rotationRight(node);

        // RR case
        if (balance < -1 && val > node->right->key)
            return rotationLeft(node);

        // LR case
        if (balance > 1 && val > node->left->key)
        {
            node->left = rotationLeft(node->left);
            return rotationRight(node);
        }

        // RL case
        if (balance > 1 && val < node->left->key)
        {
            node->right = rotationRight(node->right);
            return rotationLeft(node);
        }

        return node;
    }
};