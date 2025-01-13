#include <bits/stdc++.h>

int solve(vector<int> &a, vector<int> &b)
{
    return 0;
}

int main()
{
    FAST_IO
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
