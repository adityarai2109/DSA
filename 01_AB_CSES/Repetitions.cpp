#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll solve(string &s)
{
    ll mx = 1, n = s.size(), i = 0;
    while (i < n)
    {
        ll cnt = 1;
        while (s[i] == s[i + 1])
        {
            cnt++;
            i++;
        }
        i++;
        mx = max(cnt, mx);
    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
