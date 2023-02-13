#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll ans = 0, N;
vector<ll> a(102, 0), b(102, 0);
vector<vector<ll>> temp(102, vector<ll>(20001, 0));

void dfs(ll idx, ll x, ll y)
{
    if (idx == N + 1)
    {
        ans = max(ans, min(x, y));
        return;
    }
    if (temp[idx][x] >= y and temp[idx][x] != 0)
        return;
    temp[idx][x] = y;
    dfs(idx + 1, x, y + b[idx]);
    dfs(idx + 1, x + a[idx], y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        ans = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < 20001; ++j)
                temp[i][j] = 0;
        for (int i = 1; i <= N; i++)
            cin >> a[i];
        for (int i = 1; i <= N; i++)
            cin >> b[i];
        dfs(1, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}
