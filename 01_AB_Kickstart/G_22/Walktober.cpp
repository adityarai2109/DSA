#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

int solve(int m, int n, int p, vector<vector<int>> &v)
{
    int ans = 0;
    for (size_t j = 0; j < n; j++)
    {
        int mx = INT_MIN;
        for (size_t i = 0; i < m; i++)
            mx = max(mx, v[i][j]);
        ans += mx - v[p - 1][j];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int m, n, p;
        cin >> m >> n >> p;
        vector<vector<int>> v;
        for (size_t i = 1; i <= m; i++)
        {
            vector<int> temp(n);
            for (auto &x : temp)
                cin >> x;
            v.push_back(temp);
        }
        cout << "Case #" << t << ": " << solve(m, n, p, v) << "\n";
    }
    return 0;
}
