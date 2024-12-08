#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

void ConHelper(vector<vector<int>> &g, vector<bool> &vis, int src)
{
    vis[src] = 1;
    for (auto i : g[src])
    {
        if (vis[i] == 0)
            ConHelper(g, vis, i);
    }
}

int connectedComponents(vector<vector<int>> &g)
{
    int n = g.size();
    vector<bool> vis(n, 0);
    int ans = 0;

    // code to count number of connected components
    for (int i = 0; i < n; i++)
    {
        // counting the number of dfs
        if (vis[i] == 0)
        {
            ConHelper(g, vis, i);
            ans++;
        }
    }
    return ans;
}

bool dfsHasCycle(vector<int> adj[], int n, vector<int> &vis, int src, int par)
{
    vis[src] = 1;
    for (auto i : adj[src])
    {
        if (vis[i] == 0)
        {
            if (dfsHasCycle(adj, n, vis, i, src))
                return 1;
        }
        else if (i != par)
        {
            return 1;
        }
    }
    return 0;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0 and dfsHasCycle(adj, V, vis, i, -1))
            return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 8;
    vector<vector<int>> p = {{1, 2}, {2, 3}, {2, 4}, {3, 5}, {6, 7}, {1, 5}};
    vector<vector<int>> g(n);
    for (auto i : p)
    {
        g[i[0] - 1].push_back(i[1] - 1);
        g[i[1] - 1].push_back(i[0] - 1);
    }
    // cout << connectedComponents(g);
    return 0;
}
