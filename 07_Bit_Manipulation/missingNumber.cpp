#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

/*
 XOR of a number with itself is 0 i.e. x ^ x = 0 and the given array arr[] has numbers in range [1, n]. This means that the result of XOR of first n natural numbers with the XOR of all the array elements will be the missing number. To do so, calculate XOR of first n natural numbers and XOR of all the array arr[] elements, and then our result will be the XOR of both the resultant values.
*/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int x1 = 0, x2 = 0;
        for (auto i : nums)
            x1 ^= i;
        for (int i = 1; i <= nums.size(); i++)
            x2 ^= i;
        return x1 ^ x2;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
