#include "bits/stdc++.h"
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<vector<char>> solve(int n, int k, int r, int c)
{
    vector<vector<char>> ans(n, vector<char>(n, '.'));
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        for (auto i : solve(n, k, r, c))
        {
            for (auto j : i)
                cout << j;
            cout << "\n";
        }
    }
    return 0;
}
