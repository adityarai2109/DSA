#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> nums = {11, 12, 15, 18, 2, 5, 6, 8};
    vector<int> nums2 = {1, 2, 3};

    int times_rotated(vector<int> &nums, int s, int e)
    {
        int n = nums.size();
        while (s <= e)
        {
            int m = s + (e - s) / 2, next = (m + 1) % n, prev = (m - 1) % n;
            if (nums[m] < nums[prev] and nums[m] < nums[next])
                return m;
            else if (nums[m] > nums[next]) // choose unsorted array
                s = m + 1;
            else
                e = m - 1;
        }
        return 0;
    }
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.times_rotated(S.nums2, 0, S.nums2.size() - 1);
    return 0;
}
