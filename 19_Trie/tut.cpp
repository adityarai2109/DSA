#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool is_terminal;
    Node(char data)
    {
        this->data = data;
        this->m.clear();
        this->is_terminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie() { root = new Node('\0'); }
    void insert(string str)
    {
        Node *temp = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (temp->m.find(str[i]) == temp->m.end())
            {
                Node *n = new Node(str[i]);
                temp->m[str[i]] = n;
            }
            temp = temp->m[str[i]];
        }
        temp->is_terminal = true;
    }

    Node *getRoot()
    {
        return root;
    }
};

class Solution
{
public:
    vector<vector<string>> ans;

    void generatePaths(
        Node *root,
        string &prefix,
        priority_queue<string, vector<string>, greater<string>> &pq,
        string &p)
    {
        if (root->is_terminal == true)
        {
            pq.push(prefix + p);
        }
        for (auto i : root->m)
        {
            p += i.first;
            generatePaths(i.second, prefix, pq, p);
            p.pop_back();
        }
    }

    void solve(Node *root, string s)
    {
        priority_queue<string, vector<string>, greater<string>> pq;
        Node *r = root;
        int n = s.size();
        for (auto i : s)
        {
            r = r->m[i];
            if (r == NULL)
                break;
        }
        string p = "";
        generatePaths(r, s, pq, p);
        int k = 3;
        vector<string> v;
        while (!pq.empty() and k > 0)
        {
            auto c = pq.top();
            pq.pop();
            v.push_back(c);
            k--;
        }
        ans.push_back(v);
    }

    vector<vector<string>> suggestedProducts(
        vector<string> &products,
        string searchWord)
    {
        Trie t;
        for (auto p : products)
            t.insert(p);
        Node *r = t.getRoot();
        int n = searchWord.size();
        for (int i = 0; i < n; i++)
        {
            solve(r, searchWord.substr(0, i + 1));
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution S;
    vector<string> p = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    vector<vector<string>> ans = S.suggestedProducts(p, "mouse");
    for (auto a : ans)
    {
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
