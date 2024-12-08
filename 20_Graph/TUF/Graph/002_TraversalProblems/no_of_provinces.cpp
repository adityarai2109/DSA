#include <bits/stdc++.h>

class Solution
{
  // adjacency list
  void dfs(int node, vector<vector<int>> &graph, vector<int> &vis)
  {
    vis[node] = 1;
    for (auto nbr : graph[node])
      if (vis[nbr] == 0)
        dfs(nbr, graph, vis);
  }

  // for n*n matrix
  void dfs_matrix(int node, vector<vector<int>> adj, vector<int> &vis)
  {
    vis[node] = 1;
    int n = vis.size();
    for (int i = 0; i < n; i++)
      if (adj[node][i] == 1 and vis[i] == 0)
        dfs_matrix(i, adj, vis);
  }

public:
  int numProvinces(vector<vector<int>> adj)
  {
    int n = adj.size();
    vector<int> vis(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      if (vis[i] == 0)
      {
        dfs_matrix(i, adj, vis);
        ans++;
      }
    }
    return ans;
  }
};

int main()
{
  FAST_IO;
  return 0;
}