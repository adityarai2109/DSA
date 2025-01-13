#include <bits/stdc++.h>

class Solution
{
public:
    int solve(vector<int> &money, int idx, int n, vector<int> &dp)
    {
        // nothing added so 0
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = money[idx] + solve(money, idx + 2, n, dp);
        int discard = solve(money, idx + 1, n, dp);
        return max(pick, discard);
    }

    // circular houses
    int houseRobber(vector<int> &money)
    {
        int n = money.size();
        vector<int> dp(n + 1, -1);
        return max(solve(money, 0, n - 1, dp), solve(money, 1, n, dp));
    }
};

int main()
{
    FAST_IO

    return 0;
}
