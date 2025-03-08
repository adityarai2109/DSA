#include <bits/stdc++.h>

class Solution
{
public:
    int dp[51][51][51][51];

    int solve(vector<vector<int>> &grid, int r1, int c1, int r2, int c2)
    {
        if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        if (dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];
        if (r1 == 0 && c1 == 0 and r2 == 0 and c2 == 0)
            return grid[0][0];
        int picked = 0;
        if (r1 == r2 && c1 == c2)
            picked += grid[r1][c1];
        else
            picked += grid[r1][c1] + grid[r2][c2];
        int next = INT_MIN;
        next = max(next, solve(grid, r1 - 1, c1, r2 - 1, c2));
        next = max(next, solve(grid, r1, c1 - 1, r2, c2 - 1));
        next = max(next, solve(grid, r1, c1 - 1, r2 - 1, c2));
        next = max(next, solve(grid, r1 - 1, c1, r2, c2 - 1));
        return dp[r1][c1][r2][c2] = picked + next;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, solve(grid, n - 1, n - 1, n - 1, n - 1));
    }
};

class Solution2
{
public:
    int dp[51][51][51];

    // 3 parameter optimisation
    int solve(vector<vector<int>> &grid, int r1, int c1, int c2)
    {
        int r2 = r1 + c1 - c2;
        if (r1 < 0 || c1 < 0 || r2 < 0 || c2 < 0 ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        if (dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];
        if (r1 == 0 && c1 == 0 and r2 == 0 and c2 == 0)
            return grid[0][0];
        int picked = 0;
        if (r1 == r2 && c1 == c2)
            picked += grid[r1][c1];
        else
            picked += grid[r1][c1] + grid[r2][c2];
        int next = INT_MIN;
        // both pickers are moving together
        next = max(next, solve(grid, r1 - 1, c1, c2));
        next = max(next, solve(grid, r1, c1 - 1, c2 - 1));
        next = max(next, solve(grid, r1, c1 - 1, c2));
        next = max(next, solve(grid, r1 - 1, c1, c2 - 1));
        return dp[r1][c1][c2] = picked + next;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, solve(grid, n - 1, n - 1, n - 1));
    }
};

int main()
{
    FAST_IO

    return 0;
}
