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
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);

        int diameter = height(root->left) + height(root->right);

        return max(max(l, r), diameter);
    }
};

class Solution
{
public:
    int solve(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left, res), r = solve(root->right, res);

        // when node is not the parent of the path
        int ch1 = max(max(l, r) + root->val, root->val);
        // when node is the parent of the path
        int ch2 = max(ch1, l + r + root->val);

        res = max(ch2, res);
        return ch1;
    }

    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};

class Solution
{
public:
    int solve(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;
        // to handle -ve values
        int l = max(0, solve(root->left, res)), r = max(0, solve(root->right, res));
        // when node has to pass the answer to parent
        int temp = max(l, r) + root->val;
        // if node is leaf node, it can reject the child answers
        if (root->left == NULL and !root->right == NULL)
            temp = max(temp, root->val);

        // when node is the parent node of the path
        int ans = max(temp, l + r + root->val);
        res = max(res, ans);
        return temp;
    }

    int findMaxSum(TreeNode *root)
    {
        // Your code goes here
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};

int main()
{
    FAST_IO

    return 0;
}
