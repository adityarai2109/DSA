#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<vector<ll>> dp;

ll solve(string &a, string &b, ll n, ll m)
{
    if (a == b)
        return 0;
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (a[n - 1] == b[m - 1])
        return dp[n][m] = solve(a, b, n - 1, m - 1);
    else
        return dp[n][m] = 1 + min(solve(a, b, n - 1, m - 1), min(solve(a, b, n - 1, m), solve(a, b, n, m - 1)));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string a, b;
        cin >> a >> b;
        ll n = a.size(), m = b.size();
        dp.resize(n + 1, vector<ll>(m + 1, -1));
        cout << solve(a, b, n, m) << "\n";
    }
    return 0;
}
