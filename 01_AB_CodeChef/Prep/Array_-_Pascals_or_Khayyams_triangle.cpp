#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

vector<vector<ll>> dp;

vector<ll> solve(ll n)
{
    if (n == 1)
        return dp[1] = {1};
    if (dp[n].size() != 0)
        return dp[n];
    vector<ll> temp = {1}, prev = solve(n - 1);
    for (size_t i = 1; i < prev.size(); i++)
        temp.push_back(prev[i - 1] + prev[i]);
    temp.push_back(1);
    return dp[n] = temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp.clear();
    int T;
    cin >> T;
    dp.resize(51, {});
    while (T--)
    {
        ll n;
        cin >> n;
        for (auto i : solve(n))
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
