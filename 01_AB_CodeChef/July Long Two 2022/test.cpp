#include <bits/stdc++.h>
using namespace std;

bool r(vector<int> &rolls, vector<int> &temp)
{
    int n1 = rolls.size(), n2 = temp.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    for (int i = 0; i <= n1; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= n2; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++)
            if (rolls[i - 1] == temp[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    return dp[n1][n2] != n2;
}

int shortestSequence(vector<int> &rolls, int k)
{
    vector<int> dice;
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
        dice.push_back(i);
    int n = pow(2, k);
    for (int i = 1; i < n; i++)
    {
        vector<int> temp;
        for (int j = 1; j < k; j++)
            if (i & (1 << j))
                temp.push_back(rolls[j]);
        if (r(rolls, temp))
        {
            for (auto i : temp)
                cout << i << " ";
            cout << "\n";
            int t = temp.size();
            ans = min(ans, t);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a = {4, 2, 1, 2, 3, 3, 2, 4, 1};
    cout << shortestSequence(a, 4);
    return 0;
}
