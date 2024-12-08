#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

int MaximumGreatness(int n, vector<int> x, vector<int> y)
{
    // Write your code here.
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > y[i])
            ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> x = {3, 5, 8, 1};
    vector<int> y = {4, 7, 2, 1};
    cout << MaximumGreatness(x.size(), x, y);
    return 0;
}
