#include <bits/stdc++.h>
using namespace std;

int ans = 0;
void printSubArrays(vector<int> arr, int start, int end, long long k)
{
    if (end == arr.size())
        return;
    else if (start > end)
        printSubArrays(arr, 0, end + 1, k);
    else
    {
        int sum = 0;
        for (int i = start; i <= end; i++)
            sum += arr[i];
        if (sum * (end - start + 1) < k)
            ans++;
        printSubArrays(arr, start + 1, end, k);
    }
    return;
}
long long countSubarrays(vector<int> &nums, long long k)
{
    printSubArrays(nums, 0, 0, k);
    return ans;
}
int main()
{
    vector<int> arr = {2, 1, 4, 3, 5};
    cout << countSubarrays(arr, 10);
    return 0;
}
