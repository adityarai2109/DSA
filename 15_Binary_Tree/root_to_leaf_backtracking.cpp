#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(Node *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL and root->right == NULL)
        {
            // end backtracking v imp
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->data);
        solve(root->left);
        solve(root->right);
        temp.pop_back();
    }

    vector<vector<int>> Paths(Node *root)
    {
        // code here
        ans.clear();
        temp.clear();
        solve(root);
        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
