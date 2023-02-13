#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

struct FenwickTree
{
    int n;
    vector<int> bit; // binary indexed tree
    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int solve(vector<int> &a)
{
    ll ans = 0, n = a.size();
    FenwickTree tree(a);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (tree.sum(i, j) >= 0)
                ans++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        vector<int> a(N);
        for (auto &i : a)
            cin >> i;
        cout << "Case #" << t << ": " << solve(a) << "\n";
    }
    return 0;
}
