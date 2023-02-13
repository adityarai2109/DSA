#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll solve(vector<ll> &a, ll N, ll K)
{
    vector<ll> pref(K + 1);
    ll ans = 0;
    for (size_t i = 1; i < N + 1; i++)
        pref[i % K] = max(a[i - 1], pref[i % K]);
    for (size_t i = 0; i < K; i++)
        ans += pref[i];
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
        int N, K;
        cin >> N >> K;
        vector<ll> a(N);
        for (auto &i : a)
            cin >> i;
        cout << solve(a, N, K) << "\n";
    }
    return 0;
}
