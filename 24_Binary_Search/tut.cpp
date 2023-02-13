#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &nums, int l, int r, int t)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == t)
            return mid;
        else if (nums[mid] < t)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
