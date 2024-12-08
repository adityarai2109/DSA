#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll power(ll x, ll y, ll p = 1e9 + 7)
{
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
    if (x == 0)
        return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << power(2, n);
    return 0;
}
