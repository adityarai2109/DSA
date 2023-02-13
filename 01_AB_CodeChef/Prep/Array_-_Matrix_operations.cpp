#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

void rotate(vector<vector<ll>> &mat)
{
    ll n = mat.size();
    for (size_t i = 0; i < n / 2; i++)
        swap(mat[i], mat[n - i - 1]);
    for (size_t i = 0; i < n; i++)
        for (size_t j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;
        vector<vector<ll>> mat(N, vector<ll>(N));
        for (size_t i = 0; i < N; i++)
            for (auto &m : mat[i])
                cin >> m;
        rotate(mat);
        rotate(mat);
        for (auto m : mat)
        {
            for (auto i : m)
                cout << i << " ";
            cout << "\n";
        }
    }
    return 0;
}
