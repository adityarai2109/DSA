#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size(), ans = 0;
    vector<int> p(n, 0);
    p[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << p[j] << " " << p[i] << "\n";
        }
    }
    for (auto i : p)
        cout << i << " ";
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {1, 1, 1};
    cout << subarraySum(v, 2);
    return 0;
}
