#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

class KnapSack
{
public:
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int w = 7;

    int knapsack(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &dp)
    {
        if (w == 0 || n == 0)
            return 0;
        if (dp[n][w] != -1)
            return dp[n][w];
        if (wt[n - 1] <= w)
        {
            return dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1, dp),
                                  knapsack(wt, val, w, n - 1, dp));
        }
        else
            return dp[n][w] = knapsack(wt, val, w, n - 1, dp);
    }

    int topDownKnapsack(vector<int> &wt, vector<int> &val, int w, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;
        for (int j = 0; j < w + 1; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= w; j++)
                if (wt[i - 1] <= j)
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
        return dp[n][w];
    }
};

class SubsetProblem
{
public:
    vector<int> nums = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    bool subsetsum(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;
        if (n == 0 and target != 0)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        if (nums[n - 1] <= target)
        {
            return dp[n][target] = (subsetsum(nums, target - nums[n - 1], n - 1, dp) || subsetsum(nums, target, n - 1, dp));
        }
        else
        {
            return dp[n][target] = subsetsum(nums, target, n - 1, dp);
        }
    }

    bool topDownSS(vector<int> &nums, int target, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        dp[0][0] = 0;
        for (int i = 1; i < n + 1; i++)
            dp[i][0] = 1;
        for (int j = 1; j < target + 1; j++)
            dp[0][j] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }
};

class EqualSumPartiton
{
public:
    vector<int> arr = {1, 5, 11, 5};
    bool topDownSS(vector<int> &nums, int target, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        dp[0][0] = 0;
        for (int i = 1; i < n + 1; i++)
            dp[i][0] = 1;
        for (int j = 1; j < target + 1; j++)
            dp[0][j] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][target];
    }

    bool possible(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        for (auto i : arr)
            sum += i;
        if (sum % 2 == 1)
            return false;
        return topDownSS(arr, sum / 2, n);
    }
};

class CountSubsetSum
{
public:
    vector<int> arr = {3, 3, 3, 3};
    int sum = 6;

    int noOfSubsets(vector<int> &arr, int sum, int n, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (arr[n - 1] <= sum)
        {
            return dp[n][sum] = noOfSubsets(arr, sum - arr[n - 1], n - 1, dp) + noOfSubsets(arr, sum, n - 1, dp);
        }
        else
        {
            return dp[n][sum] = noOfSubsets(arr, sum, n - 1, dp);
        }
    }

    int TD(vector<int> &arr, int sum, int n)
    {
        int dp[n + 1][sum + 1];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j < sum + 1; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

class MinimumSubsetSumDiff
{
public:
    vector<int> nums = {1, 2, 7};

    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= sum; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (int j = 0; j < sum + 1; j++)
        {
            if (dp[n - 1][j] == 1)
            {
                ans = min(ans, abs(sum - 2 * j));
            }
        }

        for (auto i : dp)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        return ans;
    }
};

class CountSubsetsWithDiff
{
public:
    vector<int> v = {1, 1, 2, 3};
    int d = 1;

    int solve(vector<int> &v, int d)
    {
        // s1-s2 = d
        // s1+s2 = sum
        // s1 = (d+sum)/2
        CountSubsetSum q;
        int sum = 0;
        for (auto i : v)
            sum += i;
        return q.TD(v, (d + sum) / 2, v.size());
    }
};

class TargetSum
{
public:
    vector<int> v = {1, 1, 1, 1, 1};
    int t = 3;
    int solve(vector<int> &nums, int t)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, -1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= t; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= t; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][t];
    }

    int findTargetSumWays(vector<int> &nums, int t)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        if ((sum + t) % 2)
            return 0;
        if (sum < abs(t))
            return 0;
        return solve(nums, (t + sum) / 2);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    KnapSack q1;
    // cout << q1.topDownKnapsack(q1.wt, q1.val, q1.w, q1.wt.size());

    SubsetProblem q2;
    // cout << q2.topDownSS(q2.nums, q2.sum, q2.nums.size());

    EqualSumPartiton q3;
    // cout << q3.possible(q3.arr);

    CountSubsetSum q4;
    // cout << q4.TD(q4.arr, q4.sum, q4.arr.size());

    MinimumSubsetSumDiff q5;
    // cout << q5.minimumDifference(q5.nums);

    CountSubsetsWithDiff q6;
    // cout << q6.solve(q6.v, q6.d);

    TargetSum q7; // same as count subsets with diff
    // cout << q7.findTargetSumWays(q7.v, q7.t);
    return 0;
}
