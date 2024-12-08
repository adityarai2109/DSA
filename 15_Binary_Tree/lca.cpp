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
        if (root == NULL || root == p || root == q)
            return root;
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if (!r)
            return l;
        else if (!l)
            return r;
        else
            return root;
    }
};

int main()
{
    FAST_IO

    return 0;
}
