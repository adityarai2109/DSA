#include <bits/stdc++.h>

class Solution
{

  vector<vector<int>> generateGraph(int E, int V, vector<vector<int>> &edges)
  {
    vector<vector<int>> g(V);
    // for(int i=0;i<E;i++){
    //   g[edges[i][0]].push_back(edges[i][1]);
    //   g[edges[i][1]].push_back(edges[i][0]);
    // }
    for (auto e : edges)
    {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }
    return g;
  }

  void printGraph(int V, vector<vector<int>> &graph)
  {
    for (int i = 0; i < V; i++)
    {
      cout << i << " -> ";
      for (auto nbr : graph[i])
        cout << nbr << " ";
      cout << "\n";
    }
  }

  void dfs(int node, vector<vector<int>> &graph,vector<int> &vis){
    vis[node]=1;
    for(auto nbr:graph[node]){
      if(vis[nbr]==0){
        dfs(nbr,graph,vis);
      }
    }
  }

public:
  int findNumberOfComponent(int E, int V, vector<vector<int>> &edges)
  {
    vector<vector<int>> graph = generateGraph(E, V, edges);
    // printGraph(V, graph);
    int components = 0;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
      if(vis[i]==0){
        dfs(i,graph,vis);
        components++;
      }
    }
    return components;
  }
};

int main()
{
  FAST_IO;
  Solution S;
  vector<vector<int>> edges = {{0, 1}, {1, 2}};
  auto res = S.findNumberOfComponent(2, 4, edges);
  cout<<res;
  return 0;
}