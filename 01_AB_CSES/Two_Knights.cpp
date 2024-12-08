#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

bool canPlace(vector<vector<ll>> &board, ll x, ll y)
{
    ll n = board.size();
    vector<pair<ll, ll>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    for (auto d : dir)
    {
        int i = x + d.first;
        int j = y + d.second;
        if (i >= 0 and i < n and j >= 0 and j < n)
        {
            if (board[i][j] == 1)
                return false;
        }
    }
    return true;
}

ll backtrack(vector<vector<ll>> &board, ll n, ll k, ll i, ll j)
{
    if (i == n)
        return k == 0;
    
}

ll solve(ll n)
{
    vector<vector<ll>> board(n, vector<ll>(n, 0));
    return backtrack(board, n, 2, 0, 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (size_t i = 1; i <= n; i++)
    {
        cout << solve(i) << "\n";
    }
    return 0;
}
