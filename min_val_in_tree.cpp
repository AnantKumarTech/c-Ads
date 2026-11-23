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

int MinInTree(TreeNode *head)
{
    if (head == NULL)
        return INT_MAX;

    return min(head->val,
               min(MinInTree(head->left),
                   MinInTree(head->right)));
}

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);

    a->left = b;
    a->right = d;
    b->left = c;
    b->right = e;
    d->left = f;

    cout << "Minimum: " << MinInTree(a) << endl;
}