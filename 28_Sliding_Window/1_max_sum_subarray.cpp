#include <bits/stdc++.h>

class Solution
{
public:
    int maximumSumSubarray(vector<int> &arr, int k)
    {
        int ans = INT_MIN;
        int s = 0, i = 0, j = 0;
        while (j < k)
        {
            s += arr[j++];
        }
        while (j < arr.size())
        {
            ans = max(ans, s);
            s += arr[j++];
            s -= arr[i++];
        }
        return max(ans, s);
    }
};

int main()
{
    FAST_IO

    return 0;
}
