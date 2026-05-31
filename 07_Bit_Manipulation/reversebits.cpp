#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

class Solution
{
public:
    void printBinary(int n)
    {
        string res = "";
        for (int i = 32; i >= 0; i--)
            res += (n & (1 << i)) ? '1' : '0';
        cout << res << "\n";
    }

    int reverseBits(int n)
    {
        int ans = 0;
        for (int i = 0; i <= 32; i++)
        {
            if (n & (1 << i))
            {
                ans |= (1 << (32 - i));
            }
        }
        printBinary(n);
        printBinary(ans);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution S;
    S.reverseBits(43261596);
    return 0;
}
