#include <bits/stdc++.h>

class Solution
{

    vector<pair<int, int>> dirs = {
        {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        int n = grid.size(), m = grid[0].size();
        if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == '1')
        {
            grid[x][y] = '2';
            for (auto d : dirs)
                dfs(grid, x + d.first, y + d.second);
        }
    }

    void printGrid(vector<vector<char>> &g)
    {
        for (auto i : g)
        {
            for (auto x : i)
                cout << x << " ";
            cout << "\n";
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        // printGrid(grid);
        return ans;
    }
};

int main()
{
    FAST_IO;

    return 0;
}