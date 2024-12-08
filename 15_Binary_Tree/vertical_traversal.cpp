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
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }

    // {x,[{y,node}]}
    map<int, vector<pair<int, int>>> m;

    void solve(TreeNode *root, int x = 0, int y = 0)
    {
        if (root == NULL)
            return;
        m[x].push_back({y, root->val});
        solve(root->left, x - 1, y + 1);
        solve(root->left, x + 1, y + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        for (auto i : m)
        {
            vector<int> lines;
            sort(i.second.begin(), i.second.end(), cmp);
            for (auto x : i.second)
                lines.push_back(x.second);
            ans.push_back(lines);
        }
        return ans;
    }
};

int main()
{
    FAST_IO

    vector<pair<int, int>> v;
    return 0;
}
