#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

int factorialWithDP(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (dp[i - 1] * i);
    }
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
