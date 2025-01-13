#include <bits/stdc++.h>

class Solution
{
public:
    int solve(
        vector<vector<int>> &matrix,
        vector<vector<int>> &dp,
        int n, int prev_task)
    {
        int m = matrix[0].size();
        if (n < 0)
            return 0;
        if (dp[n][prev_task] != -1)
            return dp[n][prev_task];
        int ans = 0;
        for (int cur_task = 0; cur_task < m; cur_task++)
        {
            if (cur_task == prev_task)
                continue;
            ans = max(ans, matrix[n][cur_task] + solve(matrix, dp, n - 1, cur_task));
        }
        return dp[n][prev_task] = ans;
    }

    int ninjaTraining(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // prev is m and not -1 as -1 is not accessible in dp
        return solve(matrix, dp, n - 1, m);
    }
};

int main()
{
    FAST_IO

    return 0;
}
