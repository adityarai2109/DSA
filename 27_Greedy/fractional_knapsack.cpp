#include <bits/stdc++.h>

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return (double)(a.first) / (double)(a.second) > (double)(b.first) / (double)(b.second);
    }

    double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // Your code here
        vector<pair<int, int>> v;
        int n = val.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back({val[i], wt[i]});
        }
        sort(v.begin(), v.end(), cmp);
        double ans = 0;
        for (auto item : v)
        {
            if (item.second <= capacity)
            {
                capacity -= item.second;
                ans += item.first;
            }
            else
            {
                ans += (double)(item.first) / (double)(item.second) * (capacity);
                capacity = 0;
            }
        }
        return ans;
    }
};

int main()
{
    FAST_IO
    /*
    8 2 10 1 9 7 2 6 4 9
    10 1 7 7 5 1 8 6 8 7
    21
    */
    return 0;
}
