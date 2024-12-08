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
    // use 0 based indexing and cal width in O(1)
    // left -> 2*i+1, right ->2*i+2

    int widthOfBinaryTree(TreeNode *root)
    {
        long long int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            // used to handle overflows
            // every row starts with 0 now
            long long int normalising_factor = q.front().second;
            long long int l, r, n = q.size();
            for (size_t i = 0; i < n; i++)
            {
                auto c = q.front();
                long long int idx = c.second - normalising_factor;
                q.pop();
                if (i == 0)
                    l = idx;
                if (i == n - 1)
                    r = idx;
                if (c.first->left)
                    q.push({c.first->left, 2 * idx + 1});
                if (c.first->right)
                    q.push({c.first->right, 2 * idx + 2});
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
