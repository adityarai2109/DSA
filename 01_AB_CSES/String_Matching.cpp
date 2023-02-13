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
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] == b[0])
        {
            int l = 0;
            while (l < a.size() and a[i] == b[l])
            {
                i++;
                l++;
            }
            ans = l;
        }
    }
    cout << ans;
    return 0;
}
