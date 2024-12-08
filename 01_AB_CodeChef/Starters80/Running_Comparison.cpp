#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll solve(vector<ll> &a, vector<ll> &b)
{
    ll n = a.size(), ans = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] <= b[i] * 2 and b[i] <= a[i] * 2)
            ans++;
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
        vector<ll> a(N), b(N);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
