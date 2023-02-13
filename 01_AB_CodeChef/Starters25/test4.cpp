#include "bits/stdc++.h"
using namespace std;

int mex(vector<int> arr)
{
    int ans = 0;

    return ans;
}

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
        vector<int> v(2 * N, 0);
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            v[i] = x;
        }
        sort(v.begin(), v.end());
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < 2 * N; i++)
        {
            if (i & 1)
            {
                a.push_back(v[i]);
            }
            else
            {
                b.push_back(v[i]);
            }
        }
        v.clear();
        int ans1 = mex(a);
        int ans2 = mex(b);
        a.clear();
        b.clear();
        if (ans1 == ans2)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
