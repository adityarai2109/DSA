#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll solve(vector<ll> &a)
{
    ll n = a.size();
    vector<ll> ngl(n, 0), ngr(n, 0);
    ngr[n - 1] = a[n - 1], ngl[0] = a[0];
    for (size_t i = 1; i < n; i++)
        ngl[i] = max(ngl[i - 1], a[i]);
    for (int i = n - 2; i >= 0; i--)
        ngr[i] = max(ngr[i + 1], a[i]);
    ll ans = 0;
    for (size_t i = 0; i < n; i++)
        ans += min(ngr[i], ngl[i]) - a[i];
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
        int N;
        cin >> N;
        vector<ll> a(N);
        for (auto &i : a)
            cin >> i;
        cout << solve(a) << "\n";
    }
    return 0;
}
