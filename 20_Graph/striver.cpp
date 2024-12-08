#include <bits/stdc++.h>
using namespace std;

// BFS
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    queue<int> q;
    vector<int> ans;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int c = q.front();
        ans.push_back(c);
        q.pop();
        for (auto x : adj[c])
        {
            if (vis[x] == 0)
            {
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    return ans;
}

// DFS
void dfs(int V, vector<int> adj[], vector<int> &vis, vector<int> &ans, int src)
{
    vis[src] = 1;
    ans.push_back(src);
    for (auto x : adj[src])
    {
        if (vis[x] == 0)
        {
            dfs(V, adj, vis, ans, x);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    vector<int> ans;
    dfs(V, adj, vis, ans, 0);
    return ans;
}

// Cycle detection using BFS(undirected)
bool helper(int src, int V, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;
    for (int j = 0; j < V; j++)
    {
        if (vis[j] == 1)
            continue;
        q.push({j, -1});
        vis[j] = 1;
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            int node = x.first;
            int par = x.second;
            for (auto i : adj[node])
            {
                if (vis[i] == 0)
                {
                    q.push({i, node});
                    vis[i] = 1;
                }
                else
                {
                    if (vis[i] == 1 and par != i)
                        return 1;
                }
            }
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
        if (helper(i, V, adj, vis))
            return 1;
    }
    return false;
}

// Cycle detection using DFS(undirected)
bool dfs(int V, vector<int> adj[], vector<int> &vis, int src, int par = -1)
{
    vis[src] = 1;
    for (auto x : adj[src])
    {
        if (vis[x] == 0)
        {
            if (dfs(V, adj, vis, x, src))
                return 1;
        }
        else if (par != x)
            return 1;
    }
    return 0;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            if (dfs(V, adj, vis, i))
                return 1;
        }
    }
    return 0;
}

// Bipartite using BFS
bool f(vector<vector<int>> &g, int src, vector<int> &vis)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for (auto i : g[c])
        {
            if (vis[i] == -1)
            {
                q.push(i);
                vis[i] = 1 - vis[c];
            }
            else if (vis[i] == vis[c])
                return 0;
        }
    }
    return 1;
}

bool isBipartite(vector<vector<int>> &g)
{
    int n = g.size();
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            if (!f(g, i, vis))
                return 0;
        }
    }
    return 1;
}

// Bipartite using DFS
bool dfs(vector<vector<int>> &g, int src, vector<int> &vis)
{
    if (vis[src] == -1)
        vis[src] = 1;
    for (auto x : g[src])
    {
        if (vis[x] == -1)
        {
            vis[x] = 1 - vis[src];
            if (!dfs(g, x, vis))
                return 0;
        }
        else if (vis[x] == vis[src])
            return 0;
    }
    return 1;
}

bool isBipartite(vector<vector<int>> &g)
{
    int n = g.size();
    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            if (!dfs(g, i, vis))
                return 0;
        }
    }
    return 1;
}

// Topological sort using DFS
void dfs(vector<int> adj[], vector<int> &vis, int src, stack<int> &s)
{
    vis[src] = 1;
    for (auto x : adj[src])
    {
        if (vis[x] == 0)
        {
            dfs(adj, vis, x, s);
        }
    }
    s.push(src);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfs(adj, vis, i, s);
        }
    }
    vector<int> ans;
    while (s.size() > 0)
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Topological sort using BFS
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> id(V, 0);
    for (int i = 0; i < V; i++)
        for (auto x : adj[i])
            id[x]++;
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (id[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        ans.push_back(c);
        for (auto x : adj[c])
        {
            if (vis[x] == 0)
            {
                id[x]--;
                if (id[x] == 0)
                {
                    q.push(x);
                }
            }
        }
    }
    return ans;
}

// Cycle detection using BFS(directed)
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    return V != topoSort(V, adj).size();
}

// Cycle detection using DFS(directed)
// TBD

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
