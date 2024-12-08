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
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    vector<ll> v = {n};
    do
    {
        if (n % 2 == 0)
        {
            v.push_back(n / 2);
            n = n / 2;
        }
        else
        {
            v.push_back(3 * n + 1);
            n = 3 * n + 1;
        }
    } while (n != 1);
    for (auto i : v)
        cout << i << " ";
    return 0;
}
