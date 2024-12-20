#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool solve(TreeNode *l, TreeNode *r)
    {
        if ((l->val == r->val) || (l == r == NULL))
            return 1;
        if (!l || !r || l->val != r->val)
            return 0;
        return solve(l->left, r->right) and solve(l->right, r->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return 1;
        return solve(root->left, root->right);
    }
};

int main()
{
    FAST_IO

    return 0;
}
