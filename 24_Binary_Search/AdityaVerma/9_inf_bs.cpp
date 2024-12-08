#include <bits/stdc++.h>

class Solution
{
public:
    // assumne n -> inf
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int bs(vector<int> &nums, int s, int e, int t)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
                return m;
            else if (t < nums[m])
                e = m - 1;
            else
                s = m + 1;
        }
        return -1;
    }

    int solve(vector<int> &nums, int t)
    {
        int n = nums.size();
        int s = 0, e = 1;
        // find the interval where t is present
        while (!(nums[s] <= t and nums[e] >= t))
        {
            s = e;
            e *= 2;
        }
        return bs(nums, s, min(e, n - 1), t);
    }
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.solve(S.nums, 7);
    return 0;
}
