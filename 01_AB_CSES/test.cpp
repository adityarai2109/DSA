#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int dfs1(vector<vector<int>> &g, int n, int bob, vector<int> &amt, vector<char> &vis)
{
    vis[bob] = 'B';
    amt[bob] = 0;
    int idx = -1;
    for (auto nbr : g[bob])
    {
        if (vis[nbr] != 'B')
            idx = min(idx, nbr);
    }
    if (idx == -1)
        return 0;
    return 1 + dfs1(g, n, idx, amt, vis);
}

int dfs(vector<vector<int>> &g, int n, int alice, vector<int> &amt, vector<char> &vis)
{
    return 0;
}

int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amt)
{
    int n = edges.size();
    vector<vector<int>> g(n);
    for (auto e : edges)
    {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    vector<char> vis(n, 'X');
    int bobmin = dfs1(g, n, bob, amt, vis);
    return dfs(g, n, 0, amt, vis);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (size_t i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    int bob;
    cin >> bob;
    vector<int> amt(n + 1);
    for (auto &i : amt)
        cin >> i;
    cout << mostProfitablePath(edges, bob, amt);
    return 0;
}
