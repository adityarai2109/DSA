#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int solve(vector<int> &v)
{
    int total = 0, n = v.size();
    for (auto i : v)
        total += i;
    int x = (50 * (n + 1)) - total;
    if (x < 0)
    {
        return 0;
    }
    else if (x >= 0 and x <= 100)
    {
        return x;
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        cout << solve(v) << "\n";
    }

    return 0;
}
