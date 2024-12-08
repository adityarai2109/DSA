#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

class LCSubsequence
{
public:
    string a = "abbccd";
    string b = "abcd";

    int TD(string a, string b, int n, int m)
    {
        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return dp[n][m];
    }

    string print(string a, string b, int n, int m)
    {
        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        string ans = "";
        int i = n, j = m;
        while (i > 0 and j > 0)
        {
            if (a[i] == b[j])
            {
                ans += a[i];
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class LCSubstring
{
public:
    string a = "ABCDGH";
    string b = "ACDGHR";
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        int ans = INT_MIN;
        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        return ans;
    }
};

// m+n-LCS
class LCSupersequence
{
public:
    string shortestCommonSupersequence(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        string ans = "";
        int i = n, j = m;
        while (i > 0 and j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                ans += a[i - 1];
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    ans += a[i - 1];
                    i--;
                }
                else
                {
                    ans += b[j - 1];
                    j--;
                }
            }
        }
        while (i > 0)
        {
            ans += a[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += b[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class LPS
{
public:
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        int m = s.size();
        int dp[n + 1][m + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

// LCS but i!=j when a[i-1]=a[j-1], print it like LCS
class LRS
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        int n = str.size();
        int dp[n + 1][n + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i <= n; i++)
        {
            dp[0][1] = 0;
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str[i - 1] == str[j - 1] and i != j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
};

int minInsertions(string s)
{
    int n = s.size();
    string t = s;
    reverse(t.begin(), t.end());
    int dp[n + 1][n + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return n - dp[n][n];
}

class LIS
{
public:
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int solve(vector<int> &nums, int n, int &ans)
    {
        if (n == 0)
            return 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[n - 1] > nums[i])
            {
                solve(nums, n - 1, ans);
            }
        }
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        return solve(nums, n, ans);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // LCSubsequence q1;
    // cout << q1.print(q1.a, q1.b, q1.a.size(), q1.b.size());

    // LCSubstring q2;
    // cout << q2.longestCommonSubstr(q2.a, q2.b, q2.a.size(), q2.b.size());

    // LCSupersequence q3;
    // cout << q3.solve("abac", "cab");

    // LPS q4;
    // cout << q4.longestPalindromeSubseq("cbbd");

    // Minimum number of deletion in a string to make it a palindrome
    // n-LPS

    // LRS q5;
    // cout << q5.LongestRepeatingSubsequence("AABEBCDD");

    // Sequence pattern matching
    // return LCS == t

    // Minimum number of insertion in a string to make it a palindrome
    // cout << minInsertions("mbadm");

    // LIS q6;
    // cout << q6.lengthOfLIS(q6.nums);

    return 0;
}
