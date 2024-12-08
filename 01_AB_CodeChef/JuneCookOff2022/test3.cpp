#include "bits/stdc++.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<long long int> v(n);
        for (auto &i : v)
            cin >> i;
        // cal prefix
        vector<long long int> prefix(n);
        prefix[0] = 0;
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + v[i];
    }
    return 0;
}
