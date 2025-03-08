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
    vector<string> ans;

    map<char, pair<int, int>> lookup = {
        {'D', {1, 0}},
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {-1, 0}}};

    void solve(vector<vector<int>> &mat, string &temp, int x = 0, int y = 0)
    {
        int n = mat.size();
        if (x < 0 || x >= n || y < 0 || y >= n || mat[x][y] == 0)
            return;
        if (x == n - 1 && y == n - 1)
        {
            // reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        mat[x][y] = 0;
        for (auto l : lookup)
        {
            temp.push_back(l.first);
            solve(mat, temp, x + l.second.first, y + l.second.second);
            temp.pop_back();
        }
        mat[x][y] = 1;
    }

    vector<string> findPath(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
            return {};
        ans.clear();
        string temp = "";
        solve(mat, temp);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
