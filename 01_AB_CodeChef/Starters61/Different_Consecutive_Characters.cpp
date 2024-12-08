#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

int solve(string &s)
{
    int n = s.size(), ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
            ans++;
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}
