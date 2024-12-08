#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool valid(vector<int> &nums, int pages, int k)
    {
        int c = 1, s = 0;
        for (auto i : nums)
        {
            s += i;
            if (s > pages)
            {
                c++;
                s = i;
            }
            if (c > k)
                return false;
        }
        return true;
    }

    int findPages(vector<int> &arr, int k)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (k > arr.size())
            return -1;
        int s = *max_element(arr.begin(), arr.end()), e = sum, ans = -1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (valid(arr, m, k))
            {
                ans = m;
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution S;
    vector<int> nums = {15, 10, 19, 10, 5, 18, 7};
    cout << S.findPages(nums, 5);
    return 0;
}