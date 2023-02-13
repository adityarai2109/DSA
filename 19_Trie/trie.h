#include <map>
using namespace std;
class Node
{
public:
    char data;
    map<char, Node *> m;
    bool is_terminal;

    Node(char data)
    {
        this->data = data;
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
        for (auto s : str)
        {
            if (temp->m.count(s) == 0)
            {
                Node *n = new Node(s);
                temp->m[s] = n;
            }
            temp = temp->m[s];
        }
        temp->is_terminal = true;
    }

    bool search(string str)
    {
        Node *temp = root;
        for (auto s : str)
        {
            if (temp->m.count(s) == 0)
            {
                return false;
            }
            temp = temp->m[s];
        }
        return temp->is_terminal;
    }
};