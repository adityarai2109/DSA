#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

ll solve(vector<vector<ll>> &g)
{
    ll n = g.size(), m = g[0].size(), ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            ll chip = 0;
            for (size_t k = 0; k < m; k++)
                chip += abs(g[i][k] - g[j][k]);
            ans += chip;
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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> g(n, vector<ll>(m));
        for (auto &r : g)
            for (auto &i : r)
                cin >> i;
        cout << solve(g) << "\n";
    }
    return 0;
}


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
