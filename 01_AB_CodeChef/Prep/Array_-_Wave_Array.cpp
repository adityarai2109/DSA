#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;
        vector<ll> a(N);
        for (auto &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        for (size_t i = 0; i < a.size() - 1; i += 2)
            swap(a[i], a[i + 1]);
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
