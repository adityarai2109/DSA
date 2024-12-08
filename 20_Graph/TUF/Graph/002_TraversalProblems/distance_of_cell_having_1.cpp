#include <bits/stdc++.h>

class Solution
{
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<vector<int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and vis[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while (!q.empty())
        {
            int z = q.size();
            while (z--)
            {
                auto c = q.front();
                q.pop();

                int X = c.first[0], Y = c.first[1], S = c.second;
                ans[X][Y] = S;

                for (auto d : dirs)
                {
                    int x = d.first + X;
                    int y = d.second + Y;
                    if (x >= 0 and y >= 0 and x < n and y < m and vis[x][y] == 0)
                    {
                        vis[x][y] = 1;
                        q.push({{x, y}, S + 1});
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    FAST_IO;
    return 0;
}