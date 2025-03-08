#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

template <typename T>
class Graph
{
public:
    vector<int> topologicalSort(vector<vector<T>> adj)
    {
        vector<int> ans;
        int n = adj.size();
        vector<int> indegree(n, 0);
        for (auto a : adj)
            for (auto i : a)
                indegree[i]++;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int z = q.size();
            while (z--)
            {
                auto c = q.front();
                ans.push_back(c);
                q.pop();
                for (auto nbr : adj[c])
                {
                    indegree[nbr]--;
                    if (indegree[nbr] == 0)
                    {
                        q.push(nbr);
                    }
                }
            }
        }
        return ans;
    }
};

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto p : prerequisites)
            adj[p[0]].push_back(p[1]);
        Graph<int> g;

        return g.topologicalSort(adj).size() == numCourses;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
