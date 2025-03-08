#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Solution
{
public:
    bool dfs(int V, vector<int> adj[], vector<int> &vis)
    {
        
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        if (dfs(V, adj, vis))
            return true;
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> adj[] = {{1, 2}, {0}, {0, 3}, {2}};
    Solution S;
    cout << S.isCycle(adj->size(), adj);
    return 0;
}
