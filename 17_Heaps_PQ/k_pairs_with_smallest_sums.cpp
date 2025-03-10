#include <bits/stdc++.h>

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();

        vector<vector<int>> ans;
        set<pair<int, int>> visited;
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- > 0 && !pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            int i = current.second.first;
            int j = current.second.second;
            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < n && visited.find({i + 1, j}) == visited.end())
            {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < m && visited.find({i, j + 1}) == visited.end())
            {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};

int main()
{
    FAST_IO

    return 0;
}
