#include <bits/stdc++.h>
using namespace std;

// x&-x gives the rightmost set bit
// x-(x&-x) makes the rightmost set bit as 0

struct FenwickTree
{
    int n;
    vector<int> bit; // binary indexed tree
    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    FenwickTree BIT(nums);
    cout << BIT.sum(4, 4);
    return 0;
}
