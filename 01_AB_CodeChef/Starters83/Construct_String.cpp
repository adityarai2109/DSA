#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

string solve(ll n, string &s)
{
    stack<pair<char, int>> st;
    for (auto i : s)
    {
        if (st.size() > 0 and st.top().second == 3)
        {
            pair<char, int> x = {st.top().first, 1};
            st.pop();
            st.push(x);
        }
        if (st.size() > 0 and st.top().first == i)
        {
            pair<char, int> x;
            x.first = st.top().first, x.second = st.top().second + 1;
            st.pop();
            st.push(x);
        }
        else
        {
            st.push({i, 1});
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top().first;
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        string s;
        cin >> n >> s;
        cout << solve(n, s) << "\n";
    }
    return 0;
}
