#include <bits/stdc++.h>

class Solution
{

    bool bfs(int src, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = true;
        while (!q.empty())
        {
            int z = q.size();
            while (z--)
            {
                auto c = q.front();
                q.pop();
                int x = c.first;
                int parent = c.second;

                for (auto nbr : adj[x])
                {
                    if (vis[nbr] == false)
                    {
                        vis[nbr] = true;
                        q.push({nbr, x});
                    }
                    else if (nbr != parent)
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(int src, vector<int> adj[], vector<bool> &vis, int parent = -1)
    {
        vis[src] = true;
        for (auto nbr : adj[src])
        {
            if (vis[nbr] == false)
            {
                if (dfs(nbr, adj, vis, src))
                    return true;
            }
            else if (nbr != parent)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        for (size_t i = 0; i < V; i++)
        {
            if (vis[i] == false and bfs(i, adj, vis))
                return true;
        }
        return false;
    }
};

int main()
{
    FAST_IO;

    return 0;
}