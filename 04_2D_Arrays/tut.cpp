#include "bits/stdc++.h"
using namespace std;

void spiralprint(vector<vector<int>> matrix)
{
    int start_r = 0;
    int end_r = matrix.size() - 1;
    int start_c = 0;
    int end_c = matrix[0].size() - 1;
    while (start_r <= end_r and start_c <= end_c)
    {
        for (int c = start_c; c <= end_c; c++)
            cout << matrix[start_r][c] << " ";
        for (int r = start_r + 1; r <= end_r; r++)
            cout << matrix[r][end_c] << " ";
        for (int c = end_c - 1; c >= start_c; c--)
            cout << matrix[end_r][c] << " ";
        for (int r = end_r - 1; r >= start_r + 1; r--)
            cout << matrix[r][start_c] << " ";
        start_r++;
        end_c--;
        end_r--;
        start_c++;
    }
}

pair<int, int> searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (target > matrix[n - 1][m - 1] or target < matrix[0][0])
        return {-1, -1};
    int i = 0, j = m - 1;
    while (i < n and j >= 0)
    {
        if (matrix[i][j] == target)
            return {i, j};
        (target < matrix[i][j]) ? j-- : i++;
    }

    return {-1, -1};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    // spiralprint(matrix);
    pair<int, int> ans = searchMatrix(matrix, 16);
    cout << ans.first << "," << ans.second;
    return 0;
}
