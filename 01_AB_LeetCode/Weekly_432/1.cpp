#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> zigzagTraversal(vector<vector<int>> &grid)
    {
        vector<int> ans;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                for (int j = 0; j < m; j += 2)
                    ans.push_back(grid[i][j]);
            else
                for (int j = (m % 2 == 0) ? (m - 1) : (m - 2); j >= 0; j -= 2)
                    ans.push_back(grid[i][j]);
        }
        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
