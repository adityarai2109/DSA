#include "bits/stdc++.h"
using namespace std;

long long int fact(long long int n)
{
    if (n <= 1)
        return n;
    return n * fact(n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        unordered_map<char, int> m;
        for (auto i : s)
            m[i]++;
        long long int ans = 1;
        for (auto i : m)
        {
            ans *= fact(i.second);
        }
        cout << ans << "\n";
    }
    return 0;
}
