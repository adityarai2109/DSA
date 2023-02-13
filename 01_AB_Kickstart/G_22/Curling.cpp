#include "bits/stdc++.h"
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef pair<int, int> pi;

bool circle(int x1, int y1, int x2, int y2, int r1, int r2)
{
    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return (d <= abs(r1 - r2) || d <= r1 + r2);
}

pair<int, int> solve(vector<int> &a, vector<int> &b)
{
    if (a.size() > 2)
        sort(a.begin(), a.end());
    if (b.size() > 2)
        sort(b.begin(), b.end());
    if (b.size() == 0)
        return {a.size(), 0};
    else if (a.size() == 0)
        return {0, b.size()};
    else if (a[0] < b[0])
        return {lower_bound(a.begin(), a.end(), b[0]) - a.begin(), 0};
    else
        return {0, lower_bound(b.begin(), b.end(), a[0]) - b.begin()};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        int rs, rh;
        cin >> rs >> rh;
        int n;
        cin >> n;
        vector<int> a, b;
        for (size_t i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (circle(0, 0, x, y, rh, rs))
                a.push_back((pow(x, 2) + pow(y, 2)));
        }
        int m;
        cin >> m;
        for (size_t i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            if (circle(0, 0, x, y, rh, rs))
                b.push_back((pow(x, 2) + pow(y, 2)));
        }
        int R = 0, Y = 0;
        auto ans = solve(a, b);
        R = ans.first, Y = ans.second;
        cout << "Case #" << t << ": " << R << " " << Y << "\n";
    }
    return 0;
}