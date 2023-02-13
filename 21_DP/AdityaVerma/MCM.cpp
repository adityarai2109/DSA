#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

class MGM
{
    int dp[101][101];
    int solve(int a[], int i, int j)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int temp =
                solve(a, i, k) +
                solve(a, k + 1, j) +
                a[i - 1] * a[k] * a[j];
            mn = min(mn, temp);
        }
        return dp[i][j] = mn;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, N - 1);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // MGM q1;
    // int arr[] = {40, 20, 30, 10, 30};
    // cout << q1.matrixMultiplication(5, arr);

    return 0;
}
