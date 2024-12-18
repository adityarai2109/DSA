#include <bits/stdc++.h>
using namespace std;

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
    void getAllStringsUtil(Node *r, vector<string> &ans, string &temp, int &cnt)
    {
        if (cnt == 0)
            return;
        if (r->end and cnt > 0)
        {
            ans.push_back(temp);
            cnt--;
        }
        for (auto child : r->children)
        {
            temp.push_back(child.first);
            getAllStringsUtil(child.second, ans, temp, cnt);
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
        int cnt = 3;
        getAllStringsUtil(r, ans, temp, cnt);
        return ans;
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Trie t;
        for (auto p : products)
            t.insert(p);
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); i++)
        {
            auto res = t.getAllStrings(searchWord.substr(0, i + 1));
            ans.push_back(res);
        }
        return ans;
    }
};
int main()
{
    FAST_IO
    vector<string> v = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    Solution S;
    for (const auto &r : S.suggestedProducts(v, "mouse"))
    {
        for (const auto &i : r)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
