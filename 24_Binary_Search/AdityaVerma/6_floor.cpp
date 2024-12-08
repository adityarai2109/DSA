#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> nums = {1, 3, 5, 7, 9};
    int floor(vector<int> &nums, int t)
    {
        int ans = -1;
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
            {
                return nums[m];
            }
            else if (t < nums[m])
            {
                e = m - 1;
            }
            else
            {
                // no need to use max as bs is moving towards t
                ans = nums[m];
                s = m + 1;
            }
        }
        return ans;
    }
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.floor(S.nums, 6);
    return 0;
}
