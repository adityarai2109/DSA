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
        string s;
        cin >> n >> s;
        int C = 0, N = 0, D = 0, ans = 0;
        for (auto i : s)
        {
            if (i == 'C')
                C++;
            if (i == 'N')
                N++;
            if (i == 'D')
                D++;
        }
        if (D == 0)
        {
            if (C > N)
            {
            }
        }
        C = C * 2 + D;
        N = N * 2 + D;
        (C > N) ? ans = C : ans = D;
        cout << ans * n << "\n";
    }
    return 0;
}
