#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

string string_subsets(string s)
{
    int n = s.size(), p = pow(2, n);
    string ans_subsets;
    for (int i = 0; i < p; i++)
    {
        string temp = "";
        for (int j = 0; j < n; j++)
            (i & (1 << j)) ? temp += s[j] : temp += "-";
        ans_subsets += temp + "\n";
    }
    return ans_subsets;
}

vector<vector<int>> array_subsets(vector<int> nums)
{
    vector<vector<int>> ans;
    int n = nums.size(), p = pow(2, n);
    for (int i = 0; i < p; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                temp.push_back(nums[j]);
        ans.push_back(temp);
    }
    return ans;
}

void permutations(string s, int l, int r)
{
    if (l == r)
        cout << s << "\n";
    else
        for (int i = l; i < r; i++)
        {
            swap(s[l], s[i]);
            permutations(s, l + 1, r);
            swap(s[i], s[l]);
        }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "abc";
    permutations(s, 0, s.size());
    return 0;
}
