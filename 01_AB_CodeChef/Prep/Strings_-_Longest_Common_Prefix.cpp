#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

string cp(string &a, string &b)
{
    int i = 0;
    while (a[i] == b[i])
        i++;
    return a.substr(0, i);
}

string solve(vector<string> &strs)
{
    string prefix = strs[0];
    for (size_t i = 0; i < strs.size(); i++)
        prefix = cp(strs[i], prefix);
    return prefix;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<string> a(N);
        for (auto &i : a)
            cin >> i;
        cout << solve(a) << "\n";
    }
    return 0;
}
