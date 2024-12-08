#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

vector<vector<ll>> solve(ll n, ll m)
{
    vector<vector<ll>> ans(n, vector<ll>(m, -1));
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
        cout << n * m << "\n";
        for (auto row : solve(n, m))
        {
            for (auto cell : row)
                cout << cell << " ";
            cout << "\n";
        }
    }
    return 0;
}
