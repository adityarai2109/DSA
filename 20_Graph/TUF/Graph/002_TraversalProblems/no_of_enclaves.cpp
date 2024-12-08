#include <bits/stdc++.h>

class Solution
{

    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    void dfs1(vector<vector<int>> &grid, int x, int y)
    {
        int n = grid.size(), m = grid[0].size();
        if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 1)
        {
            grid[x][y] = -1;
            for (auto d : dirs)
                dfs1(grid, x + d.first, y + d.second);
        }
    }

    void printGrid(vector<vector<int>> &g)
    {
        for (auto i : g)
        {
            for (auto x : i)
                cout << x << " ";
            cout << "\n";
        }
    }

public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        // make all boundaries islands as -1
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs1(grid, i, 0);
            if (grid[i][m - 1] == 1)
                dfs1(grid, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1)
                dfs1(grid, 0, j);
            if (grid[n - 1][j] == 1)
                dfs1(grid, n - 1, j);
        }

        // return count of enclaves
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            for (int j = 1; j < m - 1; j++)
                if (grid[i][j] == 1)
                    ans++;
        return ans;
    }
};

int main()
{
    FAST_IO;

    return 0;
}