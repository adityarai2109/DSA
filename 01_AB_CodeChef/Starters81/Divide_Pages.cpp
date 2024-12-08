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
    ll o = 0, e = 0;
    for (auto i : a)
        (i % 2 == 0) ? e++ : o++;
    if (o % 2 == 1)
        return 0;
    if (e % 2 == 0)
        return 1;
    return 1;
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
        if (solve(a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
