#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Solution
{
public:
    int dp[10001];

    int solve(vector<int> &nums, int idx)
    {
        int n = nums.size();
        if (idx >= n)
            return 1e5;
        if (idx == n - 1)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int ans = 1e5;
        for (int i = 1; i <= nums[idx]; i++)
            ans = min(ans, 1 + solve(nums, i + idx));
        return dp[idx] = ans;
    }

    int jump(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
