#include <bits/stdc++.h>

class Solution
{
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &cells, vector<vector<int>> &vis, int X, int Y)
    {
        int n = grid.size(), m = grid[0].size();
        if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1 and vis[x][y] == 0)
        {
            vis[x][y] = 1;
            cells.push_back({X - x, Y - y});
            dfs(grid, x + 1, y, cells, vis, X, Y);
            dfs(grid, x - 1, y, cells, vis, X, Y);
            dfs(grid, x, y + 1, cells, vis, X, Y);
            dfs(grid, x, y - 1, cells, vis, X, Y);
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        set<vector<vector<int>>> s;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 and vis[i][j] == 0)
                {
                    // unique key by taking coordinates to origin i.e. {X - x, Y - y}
                    vector<vector<int>> cells;
                    dfs(grid, i, j, cells, vis, i, j);
                    s.insert(cells);
                }
            }
        }
        return s.size();
    }
};

int main()
{
    FAST_IO;

    return 0;
}