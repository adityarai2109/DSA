#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

bool cmp(int a, int b)
{
    if (a > 0 and b < 0)
    {
        return a > b;
    }
    if (a < 0 and b > 0)
    {
        return b > a;
    }
    return abs(a) < abs(b);
}

long long minimumDistance(int n, int k, vector<int> &a)
{
    // Write your code here.
    sort(a.begin(), a.end(), cmp);
    int x = ceil(float(n) / float(k));
    vector<int> nums;
    for (int i = 0; i < x; i++)
    {
        int mx = 0;
        for (int j = i * k; j < (i + 1) * k and j < n; j++)
        {
            cout << a[j] << " ";
            mx = (mx, abs(a[j]));
        }
        cout << "\n";
        nums.push_back(mx);
    }
    long long ans = nums[nums.size() - 1];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        ans += 2 * nums[i];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // vector<int> a = {-5, -10, -15, 6, 5, 8, 3, 7, 4};
    vector<int> a = {2, 2, 3, 3, 3};
    cout << minimumDistance(a.size(), 3, a);
    return 0;
}
