#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

void print(vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto g : graph[i])
        {
            cout << "(" << g.first << "," << g.second << ") ";
        }
        cout << "\n";
    }
}

void dijkstra(vector<vector<pair<int, int>>> &graph, int src)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> s;

    dist[src] = 0;
    s.insert({0, src});

    while (!s.empty())
    {
        auto it = s.begin();
        int nodeDist = it->first;
        int node = it->second;
        s.erase(it);

        for (auto i : graph[node])
        {
            int nbr = i.first;
            int w = i.second;
            if (w + nodeDist < dist[nbr])
            {
                auto f = s.find({dist[nbr], nbr});
                if (f != s.end())
                    s.erase(f);

                dist[nbr] = w + nodeDist;
                s.insert({dist[nbr], nbr});
            }
        }
    }

    // shortest paths
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << "\n";
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
    vector<vector<pair<int, int>>> graph(n);
    for (auto e : edges)
    {
        graph[e[0]].push_back({e[1], e[2]});
        graph[e[1]].push_back({e[0], e[2]});
    }
    print(graph);
    dijkstra(graph, 0);
    return 0;
}
