#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    int firstOccurence(vector<int> &nums, int s, int e, int t = 1)
    {
        int ans = -1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
            {
                ans = m;
                e = m - 1;
            }
            else if (t <= nums[m])
            {
                e = s - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }

    int solve(vector<int> &nums)
    {
        if (nums[0] == 1)
            return 0;
        int s = 0, e = 1, n = nums.size();
        while (nums[e] == 0)
        {
            s = e;
            e = e * 2;
        }
        return firstOccurence(nums, s, min(e, n - 1));
    }
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.solve(S.nums);
    return 0;
}
