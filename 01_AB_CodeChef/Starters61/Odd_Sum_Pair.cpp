#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

bool solve(int a, int b, int c)
{
    if ((a + b) % 2 == 1)
        return 1;
    if ((c + b) % 2 == 1)
        return 1;
    if ((a + c) % 2 == 1)
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bool ans = solve(a, b, c);
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
