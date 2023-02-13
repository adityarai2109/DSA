#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll solve(ll n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    string s = to_string(n);
    ll ans = 1 + solve(n - (s[0] - '0'));
    for (int i = 0; i < s.size(); i++)
    {
        ans = min(ans, 1 + solve(n - s[i]));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}
