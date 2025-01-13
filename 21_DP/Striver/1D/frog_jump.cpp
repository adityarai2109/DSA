#include <bits/stdc++.h>

int solve(vector<int> &heights, int i, int n, vector<int> &dp)
{
    if (i >= n)
        return INT_MAX;
    if (i == n - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ch1 = abs(heights[i] - heights[i + 1]) +
              (solve(heights, i + 1, n, dp)) % (int)mod;
    int ch2 = abs(heights[i] - heights[i + 2]) +
              (solve(heights, i + 2, n, dp)) % (int)mod;
    return dp[i] = min(ch1, ch2);
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return solve(heights, 0, n, dp);
}

int main()
{
    FAST_IO

    return 0;
}
