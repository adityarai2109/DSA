#include <bits/stdc++.h>

class Solution
{

    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    void dfs1(vector<vector<char>> &grid, int x, int y, char a = 'O', char b = '.')
    {
        int n = grid.size(), m = grid[0].size();
        if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == 'O')
        {
            grid[x][y] = '.';
            for (auto d : dirs)
                dfs1(grid, x + d.first, y + d.second);
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>> mat)
    {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O')
                dfs1(mat, i, 0);
            if (mat[i][m - 1] == 'O')
                dfs1(mat, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 'O')
                dfs1(mat, 0, j);
            if (mat[n - 1][j] == 'O')
                dfs1(mat, n - 1, j);
        }

        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
                if (mat[i][j] == '.')
                    mat[i][j] = 'O';
            }
        return mat;
    }
};

int main()
{
    FAST_IO;

    return 0;
}