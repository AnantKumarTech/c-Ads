
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

// Count total nodes
int countNodes(TreeNode *head)
{
    if (head == NULL)
        return 0;

    return 1 + countNodes(head->left) + countNodes(head->right);
}

// Find maximum value
int MaxInTree(TreeNode *head)
{
    if (head == NULL)
        return INT_MIN;

    return max(head->val,
           max(MaxInTree(head->left),
               MaxInTree(head->right)));
}

// Find minimum value
int MinInTree(TreeNode *head)
{
    if (head == NULL)
        return INT_MAX;

    return min(head->val,
           min(MinInTree(head->left),
               MinInTree(head->right)));
}

// Find height of tree
int height(TreeNode *head)
{
    if (head == NULL)
        return 0;

    return 1 + max(height(head->left),
                   height(head->right));
}

// Count leaf nodes
int countLeaf(TreeNode *head)
{
    if (head == NULL)
        return 0;

    if (head->left == NULL && head->right == NULL)
        return 1;

    return countLeaf(head->left) +
           countLeaf(head->right);
}

// Count nodes having two children
int countTwoChildren(TreeNode *head)
{
    if (head == NULL)
        return 0;

    int count = 0;

    if (head->left != NULL && head->right != NULL)
        count = 1;

    return count +
           countTwoChildren(head->left) +
           countTwoChildren(head->right);
}

// Inorder traversal
void inorder(TreeNode *head)
{
    if (head == NULL)
        return;

    inorder(head->left);
    cout << head->val << " ";
    inorder(head->right);
}

// Preorder traversal
void preorder(TreeNode *head)
{
    if (head == NULL)
        return;

    cout << head->val << " ";
    preorder(head->left);
    preorder(head->right);
}

// Postorder traversal
void postorder(TreeNode *head)
{
    if (head == NULL)
        return;

    postorder(head->left);
    postorder(head->right);
    cout << head->val << " ";
}

int main()
{
    TreeNode *head = new TreeNode(1);

    head->left = new TreeNode(2);
    head->right = new TreeNode(3);

    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);

    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    cout << "Inorder: ";
    inorder(head);

    cout << "\nPreorder: ";
    preorder(head);

    cout << "\nPostorder: ";
    postorder(head);

    cout << "\nTotal Nodes: " << countNodes(head);
    cout << "\nMaximum: " << MaxInTree(head);
    cout << "\nMinimum: " << MinInTree(head);
    cout << "\nHeight: " << height(head);
    cout << "\nLeaf Nodes: " << countLeaf(head);
    cout << "\nTwo Children: " << countTwoChildren(head);

    return 0;
}
