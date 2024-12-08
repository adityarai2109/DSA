#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

vector<ll> solve1(vector<ll> a)
{
    sort(a.begin(), a.end(), greater<ll>());
    vector<ll> ans;
    ll likes = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] > 0)
            likes++;
        else
            likes--;
        ans.push_back(likes);
    }
    return ans;
}

vector<ll> solve2(vector<ll> a)
{
    sort(a.begin(), a.end());
    vector<ll> p, n;
    for (auto i : a)
    {
        if (i >= 0)
            p.push_back(i);
        else
            n.push_back(i);
    }
    a.clear();
    ll x = p.size(), y = n.size();
    for (size_t i = 0; i < min(x, y); i++)
    {
        a.push_back(p[i]);
        a.push_back(n[i]);
    }
    for (size_t i = min(x, y); i < x; i++)
        a.push_back(p[i]);
    for (size_t i = min(x, y); i < y; i++)
        a.push_back(n[i]);
    vector<ll> ans;
    ll likes = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] > 0)
            likes++;
        else
            likes--;
        ans.push_back(likes);
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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &i : a)
            cin >> i;
        for (auto i : solve1(a))
            cout << i << " ";
        cout << "\n";
        for (auto i : solve2(a))
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
