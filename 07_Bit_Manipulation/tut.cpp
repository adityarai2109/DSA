#include "bits/stdc++.h"
using namespace std;
bool odd(int x)
{
    return (x & 1);
}
int getIthBit(int n, int i)
{
    int mask = (1 << i);
    return (n & mask) > 0;
}
int clearIthBit(int &n, int i)
{
    int mask = ~(1 << i);
    n = (n & mask);
    return n;
}
int setIthBit(int &n, int i)
{
    int mask = (1 << i);
    n = (n | mask);
    return n;
}
int updateIthBit(int &n, int i, int value)
{
    clearIthBit(n, i);
    int mask = (value << i);
    n = (n | mask);
    return n;
}
int clearLastIthBits(int &n, int i)
{
    int mask = (-1 << i); // 111111 with left shifts
    n = n & mask;
    return n;
}
int clearBitsInRange(int &n, int i, int j)
{
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
    return n;
}
bool powerOf2(int n)
{
    return n & (n - 1);
}
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        // faster method
        n = n & (n - 1);
        count++; // iteration == answer

        // count += n & 1;
        // n = n >> 1;
    }
    return count;
}
int expo(int p, int n)
{
    int ex = 1;
    while (n > 0)
    {
        if (n & 1)
            ex = ex * p;
        p = p * p;
        n = n >> 1;
    }
    return ex;
}
int decToBin(int n)
{
    int p = 0, ans = 0;
    while (n > 0)
    {
        ans += (n & 1) * expo(10, p);
        p++;
        n = n >> 1;
    }
    return ans;
}
int main()
{
    // cout << "AND " << (5 & 7) << "\n";
    // cout << "OR " << (5 | 7) << "\n";
    // cout << "XOR " << (5 ^ 7) << "\n";
    // cout << "NOT " << (~0) << "\n"; // 2's complement
    // cout << "BINARY LEFT SHIFT " << (32 << 1) << "\n";
    // cout << "BINARY RIGHT SHIFT " << (32 >> 1) << "\n";
    // cout << odd(2) << "\n";
    // cout << odd(3) << "\n";
    // cout << getIthBit(21, 0) << "\n";
    // int n = 256; // 10000000
    // cout << clearIthBit(n, 8) << "\n";
    // n = 256; // 10000000
    // cout << setIthBit(n, 2) << "\n";
    // n = 256; // 10000000
    // cout << updateIthBit(n, 7, 1) << "\n";
    // n = 256; // 10000000
    // cout << clearLastIthBits(n, 3) << "\n";
    // n = 255; // 10000000
    // cout << clearBitsInRange(n, 2, 6) << "\n";
    // cout << powerOf2(15) << "\n";
    // cout << countSetBits(9);
    // cout << expo(2, 10);
    cout << decToBin(7);
    return 0;
}
