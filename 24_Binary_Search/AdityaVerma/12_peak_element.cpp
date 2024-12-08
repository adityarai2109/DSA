#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size(), s = 0, e = n - 1;
        if (n == 1)
            return 0;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (m - 1 >= 0 and m + 1 < n)
            {
                // check for peak
                if (nums[m] > nums[m - 1] and nums[m] > nums[m + 1])
                    return m;
                // choose nbr that is greater than m
                // if both are greater, choose any.
                else if (nums[m - 1] > nums[m])
                    e = m - 1;
                else if (nums[m] < nums[m + 1])
                    s = m + 1;
            }
            // for edges
            else if (m == 0)
            {
                if (nums[0] > nums[1])
                    return 0;
                return 1;
            }
            else if (m == n - 1)
            {
                if (nums[n - 1] > nums[n - 2])
                    return n - 1;
                return n - 2;
            }
        }
        return -1;
    }
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.findPeakElement(S.nums);
    return 0;
}
