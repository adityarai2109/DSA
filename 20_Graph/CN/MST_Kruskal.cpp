#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find(vector<int> parent, int e)
{
    if (parent[e] == e)
        return e;
    // path compression
    return parent[e] = find(parent, parent[e]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 6, e = 11;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 5},
        {2, 3, 10},
        {0, 3, 4},
        {1, 3, 3},
        {1, 2, 6},
        {3, 4, 7},
        {2, 4, 8},
        {4, 5, 2},
        {2, 5, 9},
        {3, 5, 6},
    };

    // sort to get edges greedily
    sort(edges.begin(), edges.end(), cmp);

    // for (auto e : edges)
    // cout << e[0] << "," << e[1] << " - " << e[2] << "\n";

    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // to store n-1 edges
    vector<vector<int>> MST(n - 1);

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int pu = find(parent, u);
        int pv = find(parent, v);
        if (pu != pv)
        {
            MST[count] = edges[i];
            count++;
            parent[pu] = pv;
        }
        i++;
    }
    for (auto i = 0; i < n; i++)
        cout << i << "," << parent[i] << " ";
    cout << "\n";
    for (auto i : MST)
    {
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int find(vector<int> parent, int e)
{
    if (parent[e] == e)
        return e;
    // path compression
    return parent[e] = find(parent, parent[e]);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = find(parent, u);
    v = find(parent, v);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else
    {
        parent[u] = v;
        rank[u]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 6, e = 11;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {0, 2, 5},
        {2, 3, 10},
        {0, 3, 4},
        {1, 3, 3},
        {1, 2, 6},
        {3, 4, 7},
        {2, 4, 8},
        {4, 5, 2},
        {2, 5, 9},
        {3, 5, 6},
    };

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n, 0);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<vector<int>> MST(n - 1);

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int pu = find(parent, u);
        int pv = find(parent, v);
        if (pu != pv)
        {
            MST[count] = edges[i];
            count++;
            // parent[pu] = pv;
            Union(u, v, parent, rank);
        }
        i++;
    }
    for (auto i = 0; i < n; i++)
        cout << i << "," << parent[i] << "," << rank[i] << "\n";
    cout << "\n";
    for (auto i : MST)
    {
        cout << i[0] << " " << i[1] << " " << i[2] << "\n";
    }
    return 0;
}

*/