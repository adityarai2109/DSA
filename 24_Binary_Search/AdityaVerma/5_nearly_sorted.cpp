#include <bits/stdc++.h>

class Solution
{
public:
    // check for i-1,i,i+1
    vector<int> nums = {5, 10, 30, 20, 40};

    int bs(vector<int> &nums, int t)
    {
        int s = 0, e = nums.size() - 1, n = nums.size();
        while (s <= e)
        {
            int m = s + (e - s) / 2;

            if (nums[m] == t)
                return m;
            else if (m + 1 < e and nums[m + 1] == t)
                return m + 1;
            else if (m - 1 > s and nums[m - 1] == t)
                return m - 1;

            else if (t <= nums[m])
                e = m - 2;
            else
                s = m + 2;
        }
        return -1;
    }
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.bs(S.nums, 20);
    return 0;
}
