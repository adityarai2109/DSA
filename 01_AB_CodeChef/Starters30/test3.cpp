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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (k == 0)
                break;
            if (arr[i] <= k)
            {
                ans++;
                k -= arr[i];
            }
            else
            {
                int p = ceil(arr[i] / 2);
                if (p <= k)
                {
                    ans++;
                    k -= p;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
1
3 15
4 4 5
*/