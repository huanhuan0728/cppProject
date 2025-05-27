#include <iostream>
using namespace std;

class AvlTree
{
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
};