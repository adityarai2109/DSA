#include <bits/stdc++.h>

struct Node
{
    int data;
    Node *left, *right;
};

// TODO

class Solution
{
public:
    vector<int> l, leaves, r;

    void addLeft(Node *root)
    {
        if (root == NULL || (root->left == NULL and root->right == NULL))
            return;
        l.push_back(root->data);
        if (root->left)
            root = (root->left);
        else
            root = (root->right);
    }
    void addLeaves(Node *root)
    {
        if (root == NULL)
            return;
        root = (root->left);
        if (root->left == NULL and root->right == NULL)
        {
            leaves.push_back(root->data);
        }
        root = (root->right);
    }
    void addRight(Node *root)
    {
        if (root == NULL || (root->left == NULL and root->right == NULL))
            return;
        if (root->right)
            root = (root->right);
        else
            root = (root->left);
        r.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> ans;

        addLeft(root);
        addLeaves(root);
        addRight(root);

        for (int i = 0; i < l.size(); i++)
            ans.push_back(l[i]);
        for (int i = 0; i < leaves.size(); i++)
            ans.push_back(leaves[i]);
        for (int i = 0; i < r.size(); i++)
            ans.push_back(r[i]);
        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
