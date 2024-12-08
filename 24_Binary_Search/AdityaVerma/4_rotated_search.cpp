#include <bits/stdc++.h>

class Solution
{
public:
    int bs(vector<int> &nums, int s, int e, int t)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
                return m;
            else if (nums[m] > t)
                e = m - 1;
            else
                s = m + 1;
        }
        return -1;
    }

    int pivot(vector<int> &nums)
    {
        int n = nums.size(), s = 0, e = n - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            int prev = (m - 1 + n) % n;
            int next = (m + 1) % n;
            if (nums[m] < nums[prev] and nums[m] < nums[next])
                return m;
            else if (nums[m] > nums[e])
                s = m + 1;
            else
                e = m - 1;
        }
        return 0;
    }

    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int p = pivot(nums);
        int a1 = bs(nums, 0, p - 1, target);
        if (a1 != -1)
            return a1;
        return bs(nums, p, nums.size() - 1, target);
    }
};

int main()
{
    FAST_IO

    return 0;
}
