#include <bits/stdc++.h>

class Solution
{

public:
    int solve(vector<int> &heights, int i, int n, vector<int> &dp, int k)
    {
        if (i >= n)
            return INT_MAX;
        if (i == n - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MAX;
        for (int x = 1; x <= k; x++)
        {
            int res = abs(heights[i] - heights[i + x]) +
                      (solve(heights, i + x, n, dp, k)) % (int)mod;
            ans = min(ans, res);
        }
        return dp[i] = ans;
    }

    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n + 1, -1);
        return solve(heights, 0, n, dp, k);
    }
};

int main()
{
    FAST_IO

    return 0;
}
