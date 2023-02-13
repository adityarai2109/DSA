#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

vector<vector<int>> ans;
vector<int> a;
void gen(vector<int> &v, int n)
{
    if (n == 0)
    {
        ans.push_back(a);
        return;
    }
    gen(v, n - 1);
    a.push_back(v[n - 1]);
    gen(v, n - 1);
    a.pop_back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {1, 2, 3, 4, 5};
    gen(v, v.size());
    for (auto a : ans)
    {
        for (auto i : a)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
