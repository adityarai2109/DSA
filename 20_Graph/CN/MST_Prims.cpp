#include <bits/stdc++.h>
using namespace std;

int findMinVertex(vector<int> &weights, vector<int> &visited, int n)
{
}

void prims(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n, -1), visited(n, 0), weights(n, INT_MAX);
    parent[0] = -1;
    weights[0] = 0;
    for (size_t i = 0; i < n; i++)
    {
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 5, e = 7;
    vector<vector<int>> edges = {
        {0, 4, 1},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 6},
        {2, 4, 9},
        {2, 3, 3},
        {3, 4, 5},
    };
    prims(edges, n);
    return 0;
}
