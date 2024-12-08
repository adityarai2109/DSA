#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    /*
        if root has no children return null
        if p or q is found return it
        if only 1 child return non null return it
    */

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return root;
        if (root->val < p->val and root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val and root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

int main()
{
    FAST_IO

    return 0;
}
