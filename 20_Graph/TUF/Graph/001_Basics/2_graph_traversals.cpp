#include <bits/stdc++.h>

class Solution
{

    void dfs(int node, vector<int> g[], vector<int> &vis, vector<int> &dfs_traversal)
    {
        vis[node] = 1;
        dfs_traversal.push_back(node);
        for (auto nbr : g[node])
            if (vis[nbr] == 0)
                dfs(nbr, g, vis, dfs_traversal);
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfs_traversal, vis(V, 0);
        dfs(0, adj, vis, dfs_traversal);
        return dfs_traversal;
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs, vis(V, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while (!q.empty())
        {
            int z = q.size();
            while (z--)
            {
                int c = q.front();
                q.pop();
                bfs.push_back(c);

                for (auto nbr : adj[c])
                {
                    if (vis[nbr] == 0)
                    {
                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
        }
        return bfs;
    }
};

int main()
{
    FAST_IO;

    return 0;
}