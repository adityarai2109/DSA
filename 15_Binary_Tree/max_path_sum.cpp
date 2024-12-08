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
    int solve(TreeNode *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);

        // choice 1 - choosing none or only 1 subtree
        int ch1 = max(max(l, r) + root->val, root->val);
        // choice 2 -  choosing both the subtrees
        int ch2 = max(ch1, l + r + root->val);
        ans = max(ch2, ans);
        return ch1;
    }

    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
