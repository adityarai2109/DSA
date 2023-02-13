#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

int binarySearch(int arr[], int n, int value)
{
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

void printSubarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << arr[k] << " ";
            }
            cout << "\n";
        }
    }
}

int maxsubarray(int arr[], int n)
{
    int s = 0;
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s < 0)
            s = 0;
        m = max(m, s);
    }
    return m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};

    int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "\n"
    //          << arr[i] << "->" << binarySearch(arr, n, arr[i]) << endl;
    // }
    // printSubarray(arr, n);
    cout << maxsubarray(arr, n);
    return 0;
}
