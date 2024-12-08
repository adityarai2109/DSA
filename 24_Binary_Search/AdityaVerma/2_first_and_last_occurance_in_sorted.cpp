#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> nums = {1, 2, 3, 3, 3, 3, 3, 5, 6};

    int first(vector<int> &nums, int s, int e, int t, int res = -1)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
            {
                // update candidate and search in left array
                res = m;
                e = m - 1;
            }
            else if (t < nums[m])
                e = m - 1;
            else
                s = m + 1;
        }
        return res == -1 ? -1 : res;
    }

    int last(vector<int> &nums, int s, int e, int t, int res = -1)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (nums[m] == t)
            {
                // update candidate and search in right array
                res = m;
                s = m + 1;
            }
            else if (t < nums[m])
                e = m - 1;
            else
                s = m + 1;
        }
        return res == -1 ? -1 : res;
    }
};

int main()
{
    FAST_IO
    Solution S;
    int f = S.first(S.nums, 0, S.nums.size() - 1, 3);
    int l = S.last(S.nums, 0, S.nums.size() - 1, 3);

    // count of t?
    cout << l - f + 1;

    return 0;
}
