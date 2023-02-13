#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

class NumArray
{
public:
    vector<int> tree;
    int n = 0;
    void build(vector<int> &nums, vector<int> &tree, int s, int e, int t)
    {
        if (s == e)
        {
            tree[t] = nums[s];
            return;
        }
        int mid = (s + e) / 2;
        build(nums, tree, s, mid, 2 * t + 1);
        build(nums, tree, mid + 1, e, 2 * t + 2);
        tree[t] = tree[2 * t + 1] + tree[2 * t + 2];
    }

    NumArray(vector<int> &nums)
    {
        tree.clear();
        n = nums.size();
        tree.resize(4 * n, 0);
        build(nums, tree, 0, n - 1, 0);
    }

    void updatetree(int i, int val, int s, int e, int t)
    {
        if (s == e)
        {
            tree[t] = val;
            return;
        }
        int m = (s + e) / 2;
        if (i <= m)
            updatetree(i, val, s, m, 2 * t + 1);
        else
            updatetree(i, val, m + 1, e, 2 * t + 2);
        tree[t] = tree[2 * t + 1] + tree[2 * t + 2];
    }

    void update(int index, int val)
    {
        updatetree(index, val, 0, n - 1, 0);
    }

    int sumQuery(int l, int r, int s, int e, int t)
    {
        if (s > r || e < l)
            return 0;
        if (s >= l and e <= r)
            return tree[t];
        int m = (s + e) / 2;
        int ans1 = sumQuery(l, r, s, m, 2 * t + 1);
        int ans2 = sumQuery(l, r, m + 1, e, 2 * t + 2);
        return ans1 + ans2;
    }

    int sumRange(int left, int right)
    {
        return sumQuery(left, right, 0, n - 1, 0);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {1, 2, 1};
    sort(nums.begin(), nums.end());
    NumArray *z = new NumArray(nums);
    cout << z->sumRange(0, 2);
    return 0;
}
