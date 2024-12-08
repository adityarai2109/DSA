#include "bits/stdc++.h"
using namespace std;

bool adjacent(int a, int c, int b, int d)
{
    if (a + 1 == b || a - 1 == b || c - 1 == d || c + 1 == d)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        int x1, x2;
        int y1, y2;
        cin >> n >> m >> x1 >> x2 >> y1 >> y2;
        vector<vector<int>> arr(n, vector<int>(m, 0));
        arr[x1][y1] = 1;
        if (!adjacent(x1, x2, y1, y2))
            arr[x2][y2] = 2;
        for (auto i : arr)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}

/*
2
2 2
1 1
2 2
2 3
1 1
1 2

*/