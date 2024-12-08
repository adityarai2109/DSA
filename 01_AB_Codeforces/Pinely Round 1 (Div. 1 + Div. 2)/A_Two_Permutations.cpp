#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        if (n == a and n == b)
            cout << "Yes\n";
        else if (a + b >= n - 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
