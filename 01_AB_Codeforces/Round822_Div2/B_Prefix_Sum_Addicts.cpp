#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

string solve(vector<ll> &a)
{
    ll n = a.size();
    if (n == 1)
        return "Yes";
    for (ll i = n - 2; i >= 0; i--)
        a[i + 1] -= a[i];
    for (ll i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return "No";
    return "Yes";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll N, K;
        cin >> N >> K;
        vector<ll> a(K);
        for (auto &i : a)
            cin >> i;
        cout << solve(a) << "\n";
    }
    return 0;
}
