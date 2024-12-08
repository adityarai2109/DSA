#include <bits/stdc++.h>
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
    ll n;
    cin >> n;
    if (n == 2 || n == 3)
        cout << "NO SOLUTION";
    else if (n == 4)
        cout << "2 4 1 3";
    else
    {
        for (size_t i = 1; i <= n; i++)
            if (i & 1)
                cout << i << " ";
        for (size_t i = 1; i <= n; i++)
            if (!(i & 1))
                cout << i << " ";
    }
    return 0;
}
