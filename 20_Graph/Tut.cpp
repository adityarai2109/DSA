#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

void print(vector<vector<int>> &graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto g : graph[i])
        {
            cout << g << " ";
        }
        cout << "\n";
    }
}

void bfs(vector<vector<int>> &graph, int src)
{
    int n = graph.size();
    vector<bool> vis(n, 0);
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 1;
        cout << x << " ";
        for (auto i : graph[x])
        {
            if (vis[i] == 0)
            {
                q.push(i);
            }
        }
    }
}

void dfsHelper(vector<vector<int>> &graph, int src, vector<bool> &vis)
{
    vis[src] = 1;
    cout << src << " ";
    for (auto i : graph[src])
    {
        if (vis[i] == 0)
        {
            dfsHelper(graph, i, vis);
        }
    }
}

void dfs(vector<vector<int>> &graph, int src)
{
    int n = graph.size();
    vector<bool> vis(n, 0);
    dfsHelper(graph, src, vis);
}

void topologicalSort(vector<vector<int>> &graph)
{
    /*
        FOR DIRECTED ONLY
    */
    int n = graph.size();
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto x : graph[i])
            inDegree[x]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
        for (auto i : graph[x])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                q.push(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 2},
        {0, 3, 7},
        {0, 2, 4},
        {3, 4, 3},
    };
    vector<vector<int>> graph(n);
    for (auto e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    print(graph);
    // bfs(graph, 0);
    // dfs(graph, 0);
    topologicalSort(graph);
    return 0;
}
