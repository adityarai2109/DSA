#include "bits/stdc++.h"
using namespace std;

void mergeVectors(vector<int> &v, int s, int m, int e)
{
    int i = s, j = m + 1;
    vector<int> temp;
    while (i <= m && j <= e)
        (v[i] <= v[j]) ? temp.push_back(v[i++]) : temp.push_back(v[j++]);
    while (i <= m)
        temp.push_back(v[i++]);
    while (j <= e)
        temp.push_back(v[j++]);
    for (int i = s; i <= e; i++)
        v[i] = temp[i - s];
    temp.clear();
}

void mergeSort(vector<int> &v, int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        mergeVectors(v, s, m, e);
    }
}

int parti(vector<int> &v, int s, int e)
{
    int p = v[e], i = s - 1;
    for (int j = s; j < e; j++)
        if (v[j] <= p)
            swap(v[++i], v[j]);
    swap(v[i + 1], v[e]);
    return (i + 1);
}

void quickSort(vector<int> &v, int s, int e)
{
    if (s < e)
    {
        int p = parti(v, s, e);
        quickSort(v, s, p - 1);
        quickSort(v, p + 1, e);
    }
}
// rotated search
/*
|            7
|        6
|    5
|4
|                           3
|                       2
|                   1
|_______________0__________________
*/

int search(vector<int> &nums, int target)
{
    int n = nums.size(), s = 0, e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (nums[m] == target)
            return m;
        if (nums[s] <= nums[m])
        {
            (target >= nums[s] and target <= nums[m])
                ? e = m - 1
                : s = m + 1;
        }
        else
        {
            (target <= nums[e] and target >= nums[m])
                ? s = m + 1
                : e = m - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();
    // quickSort(v, 0, n - 1);
    // mergeSort(v, 0, n - 1);
    // for (auto i : v)
    // cout << i << " ";
    vector<int> w = {4, 5, 1, 2, 3};
    cout << search(w, 5);

    return 0;
}
