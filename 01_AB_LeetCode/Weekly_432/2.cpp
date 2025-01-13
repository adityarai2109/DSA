#include <bits/stdc++.h>

class Solution
{
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>> &c, int n, int m, int b)
    {
        if (n < 0 || m < 0)
            return INT_MIN;
        if (n == 0 and m == 0)
        {
            if (b < 2 and c[0][0] < 0)
                return 0;
            return c[0][0];
        }

        if (dp[n][m][b] != INT_MIN)
            return dp[n][m][b];
        int alive = c[n][m] + max(solve(c, n - 1, m, b), solve(c, n, m - 1, b));
        if (c[n][m] < 0)
        {
            int kill = INT_MIN;
            if (b < 2)
                kill = max(solve(c, n, m - 1, b + 1), solve(c, n - 1, m, b + 1));
            return dp[n][m][b] = max(kill, alive);
        }
        return dp[n][m][b] = alive;
    }
    int maximumAmount(vector<vector<int>> &coins)
    {
        int n = coins.size(), m = coins[0].size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(3, INT_MIN)));
        return solve(coins, n - 1, m - 1, 0);
    }
};

class Solution2
{
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>> &coins, int i = 0, int j = 0, int b = 0)
    {
        int n = coins.size(), m = coins[0].size();
        if (i >= n || j >= m)
            return INT_MIN;
        if (i == n - 1 and j == m - 1)
        {
            if (coins[i][j] < 0 and b < 2)
                return 0;
            return coins[i][j];
        }
        if (dp[i][j][b] != INT_MIN)
            return dp[i][j][b];
        int pick = coins[i][j] + max(solve(coins, i, j + 1, b), solve(coins, i + 1, j, b));
        if (coins[i][j] < 0)
        {
            int unpick = INT_MIN;
            if (b < 2)
                unpick = max(solve(coins, i, j + 1, b + 1), solve(coins, i + 1, j, b + 1));
            return dp[i][j][b] = max(pick, unpick);
        }
        return dp[i][j][b] = pick;
    }
    int maximumAmount(vector<vector<int>> &coins)
    {
        int n = coins.size(), m = coins[0].size();
        dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(3, INT_MIN)));
        return solve(coins);
    }
};

int main()
{
    FAST_IO
    return 0;
}
