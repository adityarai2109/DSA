#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

int solve(int n, vector<int> &a, vector<int> &b)
{
    if (a == b)
        return 0;
    int x = 0, y = 0, diff = 0;
    for (auto i : a)
        x += i == 1;
    for (auto i : b)
        y += i == 1;
    for (int i = 0; i < n; i++)
        diff += a[i] ^ b[i];
    if (x == y)
        return 1;
    else if (diff == abs(x - y))
        return 1;
    return 1 + abs(x - y);
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
        vector<int> a(n), b(n);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        cout << solve(n, a, b) << "\n";
    }
    return 0;
}
