#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

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
        unordered_map<ll, ll> m;
        for (size_t i = 0; i < 2 * N; i++)
        {
            ll x;
            cin >> x;
            m[x]++;
        }
        ll ans = 0;
        for (auto i : m)
            if (i.second == 2)
                ans++;
        cout << ans << "\n";
    }
    return 0;
}
