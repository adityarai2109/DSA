#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

ll solve(ll l, ll r)
{
    ll ans = l, score = INT_MIN;
    for (size_t i = l; i <= min(r, l + 100); i++)
    {
        ll mn = INT_MAX, mx = INT_MIN, x = i;
        while (x > 0)
        {
            ll r = x % 10;
            mx = max(mx, r);
            mn = min(mn, r);
            x /= 10;
        }
        if (mx - mn >= score)
        {
            score = mx - mn;
            if (score == 9)
                return i;
            ans = i;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll l, r;
        cin >> l >> r;
        cout << solve(l, r) << "\n";
    }
    return 0;
}
