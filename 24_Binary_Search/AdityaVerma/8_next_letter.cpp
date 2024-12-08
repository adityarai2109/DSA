#include <bits/stdc++.h>

class Solution
{
public:
    string str = "acfh";
    char solve(string str, char k)
    {
        char ans = '!';
        int n = str.size();
        int s = 0, e = n - 1;
        k += 1;
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            if (str[m] == k)
            {
                return str[m];
            }
            else if (k < str[m])
            {
                ans = str[m];
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        return ans;
    }
};

int main()
{
    FAST_IO
    Solution S;
    cout << S.solve(S.str, 'f');
    return 0;
}
