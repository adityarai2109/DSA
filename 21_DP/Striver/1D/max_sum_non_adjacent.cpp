#include <bits/stdc++.h>

class Solution
{
public:
    int solve(vector<int> &nums, int idx, int n, vector<int> &dp)
    {
        if (idx >= n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + solve(nums, idx + 2, n, dp);
        int discard = solve(nums, idx + 1, n, dp);
        return dp[idx] = max(pick, discard);
    }

    int nonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, n, dp);
    }
};

int main()
{
    FAST_IO

    return 0;
}
