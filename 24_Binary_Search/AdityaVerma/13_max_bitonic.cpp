#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> nums = {1, 3, 8, 12, 4, 2};
    // peak element would work too
    int solve(vector<int> &nums)
    {
        int n = nums.size(), s = 0, e = n - 1;
        // no = because it's monotonic
        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] < nums[m + 1])
                s = m + 1;
            else
                e = m;
        }
        return s;
    }
    /*
    0  1  2  3   4  5
    1  3  8  12  4  2
    s     m         e
             s   m  e            once nums[m] < nums[m + 1] has reached
             s   e               e comes closer to m until s=m=e and s remains
             s/e                 as answer

    return 2
    */
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.solve(S.nums);
    return 0;
}
