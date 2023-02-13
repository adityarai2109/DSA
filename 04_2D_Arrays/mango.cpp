#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> makePrefixMatrix(vector<vector<string>> matrix)
{
    // getting sizes
    int n = matrix.size(), m = matrix[0].size();

    // initialisation
    vector<vector<int>> prefix(n, vector<int>(m, 0));

    // matrix[0][0] has no prefix
    prefix[0][0] = ((matrix[0][0] == "#") ? 1 : 0);

    // prefix for 1st row
    for (int j = 1; j < m; j++)
        prefix[0][j] = ((matrix[0][j] == "#") ? 1 : 0) + prefix[0][j - 1];

    // prefix for 1st col
    for (int j = 1; j < m; j++)
        prefix[j][0] = ((matrix[j][0] == "#") ? 1 : 0) + prefix[j - 1][0];

    // prefix for rest of the matrix
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            prefix[i][j] = ((matrix[0][j] == "#") ? 1 : 0) + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];

    return prefix;
}

int getShare(vector<vector<int>> prefix, int x, int y, int n, int m)
{
    // 0 1 2 2 2 2
    // 1 3 5 5 5 5
    // 1 4 7 7 7 7
    // 1 5 9 9 9 9
    // 2 7 12 12 12 12
    // 2 8 14 14 14 14

    int s1 = prefix[x][y];
    int s2 = prefix[x][m - 1] - s1;
    int s3 = prefix[n - 1][y] - s1;
    int s4 = prefix[n - 1][m - 1] - s1 - s2 - s3;
    cout << s1 << " " << s2 << "\n"
         << s3 << " " << s4 << "\n\n";

    return min(min(s1, s2), min(s3, s4));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<string>> land = {
        {".", "#", "#", ".", ".", "."},
        {"#", ".", ".", "#", "#", "."},
        {".", "#", ".", ".", ".", "."},
        {".", "#", "#", ".", ".", "#"},
        {"#", ".", ".", "#", "#", "."},
        {".", "#", ".", ".", ".", "."},
    };

    vector<vector<int>> prefix = makePrefixMatrix(land);

    int ans = INT_MIN, n = prefix.size(), m = prefix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, getShare(prefix, i, j, n, m));
        }
        cout << "-----------\n";
    }

    cout << ans;
    return 0;
}
