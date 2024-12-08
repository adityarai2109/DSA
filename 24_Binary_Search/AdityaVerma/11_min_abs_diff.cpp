#include <bits/stdc++.h>

class Solution1
{
public:
    vector<int> nums = {1, 3, 8, 10, 15};
    int ceil(vector<int> &nums, int t)
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
                // no need to use min as bs is moving towards t
                ans = nums[m];
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }
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
    int solve(vector<int> &nums, int t)
    {
        int x = floor(nums, t);
        int y = ceil(nums, t);
        return min(abs(t - x), abs(t - y));
    }
};

class Solution2
{

public:
    vector<int> nums = {1, 3, 8, 10, 15};
    int solve(vector<int> &nums, int s, int e, int t)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
                return 0;
            else if (nums[m] > t)
                e = m - 1;
            else
                s = m + 1;
        }
        /*
        if t is not found and when bs ends, s will be after m and e will be before m
        0 0 0 e  s
        1 2 8 10 15
        use this observation
        */
        return min(abs(nums[s] - t), abs(nums[e] - t));
    }
};

int main()
{
    FAST_IO
    Solution1 S;
    cout << S.solve(S.nums, 12);
    Solution2 S2;
    cout << S2.solve(S2.nums, 0, S2.nums.size(), 12);
    return 0;
}
