#include <bits/stdc++.h>

class Solution
{

    void fill(vector<vector<int>> &grid, int x, int y, int oc, int nc)
    {
        int n = grid.size(), m = grid[0].size();
        if (x >= 0 and y >= 0 and x < n and y < m and grid[x][y] == oc)
        {
            grid[x][y] = nc;
            fill(grid, x, y + 1, oc, nc);
            fill(grid, x, y - 1, oc, nc);
            fill(grid, x + 1, y, oc, nc);
            fill(grid, x - 1, y, oc, nc);
        }
    }

public:
    vector<vector<int>> floodFill(
        vector<vector<int>> &image,
        int sr,
        int sc,
        int newColor)
    {
        // very imp check
        if (image[sr][sc] != newColor)
            fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

int main()
{
    FAST_IO;

    return 0;
}