#include <bits/stdc++.h>

class Solution
{
    vector<vector<int>> dp;

public:
    int solve(int m, int n)
    {
        // reject
        if (m < 0 || n < 0)
            return 0;

        // only accepted
        if (m == 0 and n == 0)
            return 1;
        if (dp[m][n] != -1)
            return dp[m][n];

        // + to accumulate all possibilities
        return dp[m][n] = solve(m - 1, n) + solve(m, n - 1);
    }

    // right and down allowed
    int uniquePaths(int m, int n)
    {
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1);
    }
};

int main()
{
    FAST_IO

    return 0;
}
