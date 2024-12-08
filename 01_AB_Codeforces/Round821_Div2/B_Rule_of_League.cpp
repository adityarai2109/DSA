#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<ll> solve(ll n, ll x, ll y)
{
    vector<ll> ans;

    if (ans.size() == 0)
        return {-1};
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        for (auto i : solve(n, x, y))
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
