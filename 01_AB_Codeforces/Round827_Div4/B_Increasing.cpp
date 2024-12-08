#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

string solve(vector<ll> &a)
{
    ll n = a.size();
    if (n == 1)
        return "YES";
    sort(a.begin(), a.end());
    for (size_t i = 1; i < n; i++)
        if (a[i] == a[i + 1])
            return "NO";
    return "YES";
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
        cout << solve(a) << "\n";
    }
    return 0;
}
