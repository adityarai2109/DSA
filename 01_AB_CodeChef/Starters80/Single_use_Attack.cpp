#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

int solve(int h, int x, int y)
{
    h -= y;
    int attacks = 1;
    while (h > 0)
    {
        h -= x;
        attacks++;
    }
    return attacks;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int h, x, y;
        cin >> h >> x >> y;
        cout << solve(h, x, y) << "\n";
    }
    return 0;
}
