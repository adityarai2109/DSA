/*
You are given an array [A1,…,AN]. You want to split it into several (≥2)

subarrays so that the following condition holds:

    Calculate the sum of elements in each subarray. Then, the AND of all these sums is nonzero, where AND denotes the bitwise AND operation.

Determine if it's possible. If it's possible, find one such split. You don't have to minimize the number of subarrays.
Input Format

    The first line of the input contains a single integer T

−
the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer N
−
the length of the array.
The second line of each test case contains N
space-separated integers A1,A2,…,AN

    .

Output Format

For each test case, if it's not possible to split the array so that the condition from the statement holds, output NO.

Otherwise, output YES. In the next line, output K
(2≤K≤N) −

the number of subarrays you are splitting into.

In the i
-th of the next K lines, output two integers Li,Ri (1≤Li≤Ri≤N), where [Li,Ri] denotes the i

-th subarray.

Each number from 1
to N has to appear in exactly one of the segments [Li,Ri]

.

You can output each letter in either uppercase or lowercase. You can output any solution. You don't have to minimize K

.
Constraints

    1≤T≤105

2≤N≤105
0≤Ai<230
Sum of N
over all test cases doesn't exceed 2⋅105

Sample Input 1

5
4
1 9 8 4
3
0 0 0
2
16 15
5
1 2 6 24 120
7
8 6 0 16 24 0 8

*/
#include "bits/stdc++.h"
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
    }
    return 0;
}
