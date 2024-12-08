#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    //{x,{y,val}}
    map<int, pair<int, int>> m;

    void solve(Node *root, int x = 0, int y = 0)
    {
        if (root == NULL)
            return;
        if (m.count(x))
        {
            // = handle a clash of same coordinates
            if (y >= m[x].first)
                m[x] = {y, root->data};
        }
        else
        {
            m[x] = {y, root->data};
        }
        solve(root->left, x - 1, y + 1);
        solve(root->right, x + 1, y + 1);
    }

    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> ans;
        m.clear();
        solve(root);
        for (auto i : m)
            ans.push_back(i.second.second);
        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
