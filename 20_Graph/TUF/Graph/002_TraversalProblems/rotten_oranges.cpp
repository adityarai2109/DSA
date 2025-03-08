#include <bits/stdc++.h>

class Solution
{
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), t = 0, fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
                else if (grid[i][j] == 1)
                    fresh++;

        // early exit
        if (fresh == 0)
            return 0;

        while (!q.empty())
        {
            int z = q.size();
            bool rotted = false;

            while (z--)
            {
                pair<int, int> c = q.front();
                q.pop();

                for (auto d : dirs)
                {
                    int x = d.first + c.first, y = d.second + c.second;
                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        q.push(make_pair(x, y));
                        fresh--;
                        rotted = true;
                    }
                }
            }
            // flag mark only if rotten
            if (rotted)
                t++;
        }

        return fresh == 0 ? t : -1;
    }
};

int main()
{
    FAST_IO;

    return 0;
}