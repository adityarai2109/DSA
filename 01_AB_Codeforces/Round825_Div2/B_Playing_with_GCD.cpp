#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

string solve(vector<ll> &a)
{
    ll n = a.size(), sum = 0;
    for (auto i : a)
        sum += i;
    if (sum % n == 0)
        return "YES";
    return "NO";
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
