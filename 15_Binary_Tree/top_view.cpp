#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *left, *right;
};

// bfs to ensure top view
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.

    vector<int> topView(Node *root)
    {
        // code here
        map<int, int> m;
        vector<int> ans;
        queue<pair<int, Node *>> q;
        q.push({0, root});
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                auto cur = q.front();
                int line = cur.first;
                Node *curNode = cur.second;
                q.pop();
                if (m.count(line) == 0)
                {
                    m[line] = curNode->data;
                }
                if (curNode->left)
                {
                    q.push({line - 1, curNode->left});
                }
                if (curNode->right)
                {
                    q.push({line + 1, curNode->right});
                }
            }
        }
        for (auto i : m)
            ans.push_back(i.second);
        return ans;
    }
};
int main()
{
    FAST_IO

    return 0;
}
