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
        int N;
        cin >> N;
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            m1[a]++;
            m2[b]++;
        }
        int ans = 0;
        for (auto i : m1)
            ans++;
        for (auto i : m2)
            ans++;
        cout << ans << "\n";
    }
    return 0;
}
