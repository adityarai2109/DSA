#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

void bfs(vector<vector<pair<int, int>>> &graph, int src, vector<bool> &vis)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto i : m[x])
        {
            if (vis[i] == 0)
                q.push(i);
            vis[i] = 1;
        }
    }
}

int shortestJourney(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<pair<int, int>>> graph(n);
    for (auto e : edges)
    {
        graph[e[0]].push_back({e[1], e[2]});
        graph[e[1]].push_back({e[0], e[2]});
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> " << graph[i].size() << "\n";
    //     for (auto j : graph[i])
    //     {
    //         cout << "(" << j.first << "," << j.second << ") ";
    //     }
    //     cout << "\n";
    // }
    int min
    vector<bool> vis(n, 0);
    queue<int> q;

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 2}, {1, 3, 3}};
    cout << shortestJourney(4, edges);
    return 0;
}
