#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll dp[101][1000001];

ll total;

ll solve(vector<ll> &a, ll k, ll n)
{
    if (n == 0)
    {
        if (k == 0)
            return 1;
        return 0;
    }
    if (dp[n][k] != -1)
        return dp[n][k];
    if (a[n - 1] <= k)
    {
        return dp[n][k] = solve(a, k - a[n - 1], total) + solve(a, k, n - 1);
    }
    else
    {
        return dp[n][k] = solve(a, k, n - 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    ll n, k;
    cin >> n >> k;
    total = n;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    cout << solve(a, k, n);
    return 0;
}
