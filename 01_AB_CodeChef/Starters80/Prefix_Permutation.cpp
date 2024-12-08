#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

vector<ll> solve(ll n)
{
    if (n % 2 == 1)
        return {-1};
    vector<ll> a;
    for (size_t i = 0; i < n; i++)
        a.push_back(i + 1);
    for (size_t i = 3; i < n; i += 2)
        swap(a[i], a[i - 1]);
    return a;
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
        for (auto i : solve(n))
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
