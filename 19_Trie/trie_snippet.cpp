#include <bits/stdc++.h>

struct Node
{
    char ch;
    map<char, Node *> children;
    bool end;
    Node() : ch('\0'), end(false) {}
    Node(char character) : ch(character), end(false) {}
    Node(char character, map<char, Node *> childnodes) : ch(character), children(childnodes), end(false) {}
};

class Trie
{
    void getAllStringsUtil(Node *r, vector<string> &ans, string &temp)
    {
        if (r->end)
            ans.push_back(temp);
        for (auto child : r->children)
        {
            temp.push_back(child.first);
            getAllStringsUtil(child.second, ans, temp);
            temp.pop_back();
        }
    }

public:
    Node *root;
    Trie() { root = new Node(); }

    void insert(string word)
    {
        Node *temp = root;
        for (auto w : word)
        {
            if (temp->children.count(w) == 0)
            {
                Node *nn = new Node(w);
                temp->children[w] = nn;
            }
            temp = temp->children[w];
        }
        temp->end = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (auto w : word)
        {
            if (temp->children.count(w) == 0)
                return 0;
            temp = temp->children[w];
        }
        return temp->end;
    }

    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (auto p : prefix)
        {
            if (temp->children.count(p) == 0)
                return 0;
            temp = temp->children[p];
        }
        return 1;
    }

    vector<string> getAllStrings(string prefix = "")
    {
        Node *r = root;
        for (auto p : prefix)
        {
            if (r->children.count(p))
                r = r->children[p];
            else
                return {};
        }
        vector<string> ans;
        string temp = prefix;
        getAllStringsUtil(r, ans, temp);
        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
