#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

int wines(vector<int> &p, int i, int n, int x)
{
    if (i >= n)
        return 0;
    return max(
        p[i] * x + wines(p, i + 1, n, x + 1),
        p[n - 1] * x + wines(p, i, n - 1, x + 1));
}

int wines2(vector<int> &p)
{
    int n = p.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    // 6   19  23
    // 0   15  21
    // 0   0   9
    // traingle DP

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dp[i][i] = n * p[i];
            if (i < j)
            {
                int x = n - (j - i);
                dp[i][j] = max(p[i] * x + dp[i + 1][j],
                               p[j] * x + dp[i][j - 1]);
            }
        }
    }
    return dp[n][0];
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // vector<int> prices = {2, 3, 5};
    // cout << wines(prices, 0, prices.size(), 1);
    // cout << wines2(prices);

    return 0;
}
