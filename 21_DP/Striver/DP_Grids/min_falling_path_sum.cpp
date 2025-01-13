#include <bits/stdc++.h>

// Recursive gave TLE
class Solution
{
    vector<vector<int>> dp;

public:
    int solve(vector<vector<int>> &matrix, int i, int j)
    {
        int n = matrix.size(), m = matrix[0].size();
        if (i < 0)
            return 0;
        if (j < 0 || j >= m)
            return INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = matrix[i][j] + min(solve(matrix, i - 1, j), min(solve(matrix, i - 1, j - 1), solve(matrix, i - 1, j + 1)));
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        int ans = INT_MAX;
        for (size_t j = 0; j < m; j++)
            ans = min(ans, solve(matrix, n - 1, j));
        return ans;
    }
};

class Solution2
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int mid = dp[i - 1][j];
                int right = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(min(left, right), mid);
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

int main()
{
    FAST_IO

    return 0;
}
