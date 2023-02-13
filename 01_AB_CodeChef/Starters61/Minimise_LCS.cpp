#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

ll solve(string &a, string &b)
{
    int ans = 0;
    unordered_map<char, int> x, y;
    for (auto i : a)
        x[i]++;
    for (auto i : b)
        y[i]++;
    for (char i = 'a'; i <= 'z'; i++)
    {
        int temp = min(x[i], y[i]);
        if (ans < temp)
            ans = temp;
    }
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
        int N;
        cin >> N;
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
