#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<vector<ll>> solve(vector<ll> &a)
{
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<ll> a(N);
        for (auto &i : a)
            cin >> i;
        auto ans = solve(a);
        cout << ans.size() << "\n";
        for (auto i : ans)
        {
            for (auto e : i)
                cout << e << " ";
            cout << "\n";
        }
    }
    return 0;
}
