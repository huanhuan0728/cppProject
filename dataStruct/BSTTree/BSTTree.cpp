#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    TreeNode *root;

    TreeNode *insert(TreeNode *node, int val);
    TreeNode *remove(TreeNode *node, int val);
    TreeNode *findMin(TreeNode *node);
    void inorder(TreeNode *node);

public:
    BST() : root(nullptr) {}
    void insert(int val)
    {
        root = insert(root, val);
    }
    void remove(int val)
    {
        root = remove(root, val);
    }
    bool search(int val);
    void inorderTraversal()
    {
        inorder(root);
    }
};

TreeNode *BST::insert(TreeNode *node, int val)
{
    if (!node)
    {
        return new TreeNode(val);
    }
    if (val < node->val)
    {
        node->left = insert(node->left, val);
    }
    else if (val > node->val)
    {
        node->right = insert(node->right, val);
    }

    return node;
}

TreeNode *BST::findMin(TreeNode *node)
{
    while (node && node->left)
    {
        node = node->left;
    }

    return node;
}

TreeNode *BST::remove(TreeNode *node, int val)
{
    if (!node)
        return nullptr;

    if (val < node->val)
    {
        node->left = remove(node->left, val);
    }
    else if (val > node->val)
    {
        node->right = remove(node->right, val);
    }
    else
    { // 找到目标节点
        // case1: 无子节点或只有一个子节点
        if (!node->left)
        {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        // case2:有两个子节点
        TreeNode *temp = findMin(node->right);
        node->val = temp->val;
        node->right = remove(node->right, temp->val);
    }

    return node;
}

void BST::inorder(TreeNode *node)
{
    if (!node)
        return;
    else
    {
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }
}

bool BST::search(int val)
{
    TreeNode *cur = root;
    while (cur)
    {
        if (val == cur->val)
            return true;
        cur = val < cur->val ? cur->left : cur->right;
    }
    return false;
}

int main()
{
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    std::cout << "中序遍历: ";
    tree.inorderTraversal(); // 输出: 20 30 40 50 70

    tree.remove(30);
    std::cout << "\n删除后: ";
    tree.inorderTraversal(); // 输出: 20 40 50 70

    return 0;
}