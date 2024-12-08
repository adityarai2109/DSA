#include <bits/stdc++.h>

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Traverse
{
public:
    /*
    root marked with 1



    if num is 1, preorder
        - add the node to preorder
        - increase the num and push it again
        - add it's left if present
    if num is 2, inorder
        - add the node to inorder
        - increase the num and push it again
        - add it's right if present
    if num is 3, postorder
        - add to postorder
    */

    vector<vector<int>> getTreeTraversal(TreeNode *root)
    {
        // Write your code here.
        vector<int> inorder, preorder, postorder;
        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});
        while (!s.empty())
        {
            auto c = s.top();
            s.pop();
            if (c.second == 1)
            {
                preorder.push_back(c.first->data);
                c.second += 1;
                s.push(c);
                if (c.first->left)
                    s.push({c.first->left, 1});
            }
            else if (c.second == 2)
            {
                inorder.push_back(c.first->data);
                c.second += 1;
                s.push(c);
                if (c.first->right)
                    s.push({c.first->right, 1});
            }
            else
                postorder.push_back(c.first->data);
        }
        return {inorder, preorder, postorder};
    }
};

int main()
{
    FAST_IO

    return 0;
}
