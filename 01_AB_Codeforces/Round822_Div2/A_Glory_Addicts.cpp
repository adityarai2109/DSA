#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

bool cmp(pair<ll, ll> &x, pair<ll, ll> &y) { return x.second > y.second; }

ll solve(vector<pair<ll, ll>> &a, vector<pair<ll, ll>> &b)
{
    ll n = a.size(), m = b.size(), ans = 0;
    if (n == m)
        ans = -1 * min(a[0].second, b[0].second);
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll i = 0, j = 0;
    while (i < n and j < m)
    {
        ans += a[i++].second * 2 + b[j++].second * 2;
    }
    while (i < n)
    {
        ans += a[i++].second;
    }
    while (j < m)
    {
        ans += b[j++].second;
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
        int N;
        cin >> N;
        vector<ll> skills(N), damage(N);
        for (auto &i : skills)
            cin >> i;
        for (auto &i : damage)
            cin >> i;
        vector<pair<ll, ll>> a, b;
        for (size_t i = 0; i < N; i++)
            (skills[i] == 0) ? a.push_back({skills[i], damage[i]}) : b.push_back({skills[i], damage[i]});
        cout << solve(a, b) << "\n";
    }
    return 0;
}
