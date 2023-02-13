#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;





int solve(ll val, map<ll, vector<ll>> &m, vector<ll> &ans)
{
    if (m[val].size() == 0)
        return 0;
    int sum = 0;
    for (auto child : m[val])
        sum += 1 + solve(child, m, ans);
    ans[val - 1] = sum;
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    map<ll, vector<ll>> m;
    for (size_t i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        m[x].push_back(i);
    }
    // for (auto i : m)
    // {
    //     cout << i.first << " -> ";
    //     for (auto x : i.second)
    //         cout << x << " ";
    //     cout << "\n";
    // }
    vector<ll> ans(n);
    solve(1, m, ans);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
