#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

struct TreeNode
{
    int val, height;
    TreeNode *left, *right;
    TreeNode() : val(0), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, int h, TreeNode *left, TreeNode *right) : val(x), height(h), left(left), right(right) {}
};

class AVLTree
{
    /*
    4 cases:
    RR: as skewed right, rotate left
    LL: as skewed left, rotate right
    RL: rotate right, then left
    LR: rotate left, then right
    */
public:
    TreeNode *root;
    AVLTree() { root == NULL; }

    void insert(int d) {};

    void remove(int d) {};

    /*
                X
            Xl      Y
                Yl      Z
                    Zl      Zr

    skewed right to balanced

                Y
            X       Z
        Xl    Yl  Zl   Zr

    vice versa for right rotation
    */

    void leftRotation() {};

    void rightRotation() {};
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
