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
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), cmp);
        // vector used as a stack
        vector<vector<int>> s;
        for (auto e : v)
        {
            if (s.empty() || s.back()[1] < e[0])
                s.push_back(e);
            else
            {
                auto top = s.back();
                s.pop_back();
                s.push_back({top[0], max(top[1], e[1])});
            }
        }
        return s;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
