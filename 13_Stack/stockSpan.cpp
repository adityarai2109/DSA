#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

void print(stack<pair<int, int>> t)
{
    while (!t.empty())
    {
        cout << t.top().first << " " << t.top().second << "\n";
        t.pop();
    }
    cout << "\n";
}

vector<int> stockSpan(vector<int> stockPrice)
{
    vector<int> ans = {1, 2, 3};
    int n = stockPrice.size();
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        s.push(make_pair(i, stockPrice[i]));
        print(s);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> stockPrice = {100, 80, 60, 70, 60, 75, 85};
    for (auto i : stockSpan(stockPrice))
        cout << i << " ";
    return 0;
}
