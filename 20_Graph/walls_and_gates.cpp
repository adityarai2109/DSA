#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

// multi bfs
class Solution
{
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void solve(vector<vector<int>> &rooms)
    {
        int n = rooms.size(), m = rooms[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (rooms[i][j] == 0)
                    // coordinates and dist
                    q.push({i, j, 0});
        while (!q.empty())
        {
            int z = q.size();
            while (z--)
            {
                auto c = q.front();
                q.pop();
                for (auto d : dirs)
                {
                    int i = c[0] + d[0];
                    int j = c[1] + d[1];
                    if (i >= 0 && j >= 0 && i < n && j < n && rooms[i][j] == INT_MAX)
                    {
                        rooms[i][j] = c[2] + 1;
                        q.push({i, j, rooms[i][j]});
                    }
                }
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> rooms = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}};
    Solution S;
    S.solve(rooms);
    for (auto r : rooms)
    {
        for (auto i : r)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
