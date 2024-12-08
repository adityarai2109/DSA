#include <bits/stdc++.h>

class BS
{
public:
    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    BS() { sort(nums.begin(), nums.end()); }

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
        if (s > e)
            return -1;
        int m = s + (e - s) / 2;
        if (nums[m] == t)
            return m;
        else if (t < nums[m])
            return bs2(nums, s, m - 1, t);
        else
            return bs2(nums, m + 1, e, t);
    }
};

int main()
{
    FAST_IO
    BS bs;
    cout << bs.bs2(bs.nums, 0, bs.nums.size() - 1, 6) << "\n";
    cout << bs.bs1(bs.nums, 0, bs.nums.size() - 1, 10) << "\n";
    return 0;
}
