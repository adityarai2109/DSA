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
        int a, b;
        cin >> a >> b;
        a = (int)a / 2;
        if (a < b)
            cout << a << "\n";
        else
            cout << b << "\n";
    }
    return 0;
}
