#include <bits/stdc++.h>

class Solution
{

    vector<vector<int>> dp;

    int solve(vector<vector<int>> &triangle, int i, int j)
    {
        int n = triangle.size();
        if (i == n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = triangle[i][j] + min(solve(triangle, i + 1, j), solve(triangle, i + 1, j + 1));
    }

public:
    int minTriangleSum(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(triangle, 0, 0);
    }
};

int main()
{
    FAST_IO

    return 0;
}
