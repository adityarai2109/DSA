#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

int Uknapsack(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &dp)
{
    if (w == 0 || n == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
        return dp[n][w] = max(val[n - 1] + Uknapsack(wt, val, w - wt[n - 1], n, dp),
                              Uknapsack(wt, val, w, n - 1, dp));
    else
        return dp[n][w] = Uknapsack(wt, val, w, n - 1, dp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
