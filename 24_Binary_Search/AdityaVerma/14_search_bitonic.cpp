#include <bits/stdc++.h>

class Solution
{
public:
    int findPeak(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s < e)
        {
            int m = s + (e - s) / 2;
            (nums[m] < nums[m + 1]) ? s = m + 1 : e = m;
        }
        return s;
    }

    int bs1(vector<int> &nums, int s, int e, int t)
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

    int bs2(vector<int> &nums, int s, int e, int t)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
                return m;
            else if (nums[m] < t)
                e = m - 1;
            else
                s = m + 1;
        }
        return -1;
    }

    int solve(vector<int> &nums, int t)
    {
        int n = nums.size();
        int s = 0, e = n - 1;
        int pivot = findPeak(nums);
        // now solve for 0 to peak index (inc) and peak+1 to n-1 (dec)
        int ans1 = bs1(nums, 0, pivot, t);
        int ans2 = bs2(nums, pivot + 1, n - 1, t);
        return ans1 == -1 ? ans2 : ans1;
    }
};

int main()
{
    FAST_IO
    vector<int> v = {-3, 9, 18, 20, 17, 5, 1};
    Solution S;
    cout << S.solve(v, 20);
    return 0;
}
