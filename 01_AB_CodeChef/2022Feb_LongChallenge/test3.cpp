#include "bits/stdc++.h"
using namespace std;

bool xr(char a, char b)
{
    return a == b ? 0 : 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;
        int z = 0, o = 0;
        for (int i = 0; i < n; i++)
            (s[i] == '0') ? z++ : o++;
        abs(z - o <= 1) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
