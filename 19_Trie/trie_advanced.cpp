#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Node
{
public:
    char ch;
    unordered_map<char, Node *> children;
    int terminal;
    Node(char c = '\0', int t = 0)
    {
        ch = c;
        children.clear();
        terminal = t;
    }
};

class Trie
{

private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        for (auto w : word)
        {
            if (temp->children.find(w) == temp->children.end())
            {
                Node *newNode = new Node(w);
                temp->children[w] = newNode;
            }
            temp = temp->children[w];
        }
        temp->terminal++;
    }

    int countWordsEqualTo(string word)
    {
        Node *temp = root;
        for (auto w : word)
        {
            if (temp->children.find(w) == temp->children.end())
                return 0;
            temp = temp->children[w];
        }
        return temp->terminal;
    }

    int countWordsStartingWith(string word)
    {
        Node *temp = root;
        for (auto w : word)
        {
            if (temp->children.find(w) == temp->children.end())
                return 0;
            temp = temp->children[w];
        }
        int cnt = 0;
        queue<Node *> q;
        q.push(temp);
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                auto c = q.front();
                if (c->terminal > 0)
                    cnt++;
                q.pop();
                for (auto child : c->children)
                {
                    q.push(child.second);
                }
            }
        }
        return cnt;
    }

    void erase(string word)
    {
        Node *temp = root;
        for (auto w : word)
        {
            temp = temp->children[w];
        }
        temp->terminal = 0;
    }
};

int main()

{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
