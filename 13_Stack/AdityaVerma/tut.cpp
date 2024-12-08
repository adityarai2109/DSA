#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

vector<int> NGR(vector<int> &v)
{
    vector<int> ans(v.size(), -1);
    stack<int> s;
    for (int i = v.size(); i >= 0; i--)
    {
        while (!s.empty() and v[i] >= s.top())
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        s.push(v[i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {1, 3, 2, 4};
    for (auto i : NGR(v))
        cout << i << " ";
    return 0;
}
