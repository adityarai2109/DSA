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
    ll n = a.size(), s = 0, x = 0, y = 0, z;
    for (int i = 1; i <= n; i++)
    {
        x += (a[i - 1] == 0);
        y += (a[i - 1] == 1);
        z = min(x, y);
        x -= z;
        y -= z;
        s += z;
    }
    return s + y / 3;
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
