#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int row, int col1, int col2,
              vector<vector<vector<int>>> &dp)
    {
        int n = grid.size(), m = grid[0].size();

        // Base cases
        if (row == n)
            return 0; // Reached beyond last row
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return -1e8; // Out of bounds

        // If already calculated
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        // Current cell collection
        int cherries = 0;
        cherries += grid[row][col1];
        if (col1 != col2)
        { // If robots are at different positions
            cherries += grid[row][col2];
        }

        // If we are not at the last row
        if (row != n - 1)
        {
            int maxCherries = 0;
            // Try all possible combinations for next row
            for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++)
            {
                for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++)
                {
                    maxCherries = max(maxCherries, solve(grid, row + 1, newCol1, newCol2, dp));
                }
            }
            cherries += maxCherries;
        }

        return dp[row][col1][col2] = cherries;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // 3D DP array initialized with -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(grid, 0, 0, m - 1, dp);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution sol;
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}};

    cout << sol.cherryPickup(grid) << endl;

    return 0;
}
