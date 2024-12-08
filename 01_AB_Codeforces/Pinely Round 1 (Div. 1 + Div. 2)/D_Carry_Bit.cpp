#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<ll> dp;

ll mod = 1e9 + 7;

ll g(ll x)
{
    ll cnt = 0;
    while (x > 0)
    {
        cnt += (x & 1);
        x = x >> 1;
    }
    return cnt;
}

ll f(ll x, ll y)
{
    if (dp[x] == -1)
        dp[x] = g(x);
    if (dp[y] == -1)
        dp[y] = g(y);
    if (dp[x + y] == -1)
        dp[x + y] = g(x + y);
    return dp[x] + dp[y] - dp[x + y];
}

ll solve(ll n, ll k)
{
    ll cnt = 0;
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < 1 << n; j++)
        {
            // cout << i << " " << j << " " << f(i, j) << "\n";
            if (f(i, j) == k)
            {
                cnt++;
                cnt = cnt % mod;
            }
        }
    }
    return (cnt) % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    dp.resize(2 * n + 1, -1);
    cout << solve(n, k);
    return 0;
}
