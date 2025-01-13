#include <bits/stdc++.h>

class Solution
{
    vector<vector<int>> dp;

    int solve(vector<vector<int>> &matrix, int n, int m)
    {
        // reject for obstacles too
        if (n < 0 || m < 0 || matrix[n][m] == 1)
            return 0;
        if (n == 0 and m == 0)
            return 1;
        if (dp[n][m] != -1)
            return dp[n][m];
        return dp[n][m] = solve(matrix, n - 1, m) + solve(matrix, n, m - 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        dp.resize(n, vector<int>(m, -1));
        return solve(matrix, n - 1, m - 1);
    }
};

int main()
{
    FAST_IO

    return 0;
}
