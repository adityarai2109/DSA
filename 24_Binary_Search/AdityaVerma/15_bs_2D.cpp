#include <bits/stdc++.h>

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1; // top right
        while (i < n and j >= 0)
        {
            if (matrix[i][j] == target)
                return 1;
            else if (target > matrix[i][j])
                i++;
            else
                j--;
        }
        return 0;
    }
};

int main()
{
    FAST_IO

    return 0;
}
