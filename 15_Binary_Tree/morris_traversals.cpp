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
    /*
        Morris Traversal for In-order Traversal:
        1. If the current node has no left child:
            - Add the current node's value to the result.
            - Move to the right child.
        2. If the current node has a left child:
            - Find the current node's predecessor (the rightmost node in the left subtree).
            - If the predecessor's right child is null:
                - Set the predecessor's right child to the current node (create a temporary link).
                - Move to the left child of the current node.
            - If the predecessor's right child points to the current node (temporary link exists):
                - Sever the temporary link (restore the tree structure).
                - Add the current node's value to the result.
                - Move to the right child of the current node.
    */

    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<int> inorder;
        TreeNode *c = root;
        while (c != NULL)
        {
            // 1
            if (c->left == NULL)
            {
                inorder.push_back(c->val);
                c = c->right;
            }
            else
            {
                // 2.1
                TreeNode *prev = c->left;
                while (prev->right and prev->right != c)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    // 2.2
                    prev->right = c;
                    c = c->left;
                }
                else
                {
                    // 2.3
                    prev->right = NULL;
                    inorder.push_back(c->val);
                    c = c->right;
                }
            }
        }
        return inorder;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<int> preorder;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right != NULL and prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else
                {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }

    // mirror logic, go for right then left
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<int> postorder;
        TreeNode *cur = root;
        while (cur != NULL)
        {
            if (cur->right == NULL)
            {
                postorder.push_back(cur->val);
                cur = cur->left;
            }
            else
            {
                TreeNode *next = cur->right;
                while (next->left and next->left != cur)
                {
                    next = next->left;
                }
                if (next->left == NULL)
                {
                    next->left = cur;
                    postorder.push_back(cur->val);
                    cur = cur->right;
                }
                else
                {
                    next->left = NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};

int main()
{
    FAST_IO

    return 0;
}
