#include "bits/stdc++.h"
using namespace std;

int factorial(int n)
{
    return (n == 0) ? 1 : factorial(n - 1) * n;
}

int fibonacci(int n)
{
    return (n == 1 || n == 0) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

bool isSorted(vector<int> v, int i, int n)
{
    if (i == n - 1)
        return true;
    if (v[i] < v[i + 1] and isSorted(v, i + 1, n))
        return true;
    return false;
}

void print1toN(int n)
{
    if (n == 0)
        return;
    print1toN(n - 1);
    cout << n << " ";
}

void printNto1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printNto1(n - 1);
}

int firstOccurence(vector<int> v, int i, int value, int n)
{
    return 0;
}

int pw(int n, int p)
{
    if (p == 0)
        return 1;
    return n * pw(n, p - 1);
}

void bblsort(vector<int> &v, int n)
{
    if (n == 1)
        return;
    for (int j = 0; j < n - 1; j++)
    {
        if (v[j + 1] < v[j])
        {
            swap(v[j], v[j + 1]);
        }
    }
    bblsort(v, n - 1);
}

void spell(int n)
{
    if (n == 0)
        return;
    vector<string> w = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int r = n % 10;
    n = n / 10;
    spell(n);
    cout << w[r] << " ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << factorial(5);
    // cout << fibonacci(8);

    vector<int> v = {1, 2, 3, 10, 4};
    int n = v.size();
    // cout << isSorted(v, 0, n);

    // print1toN(10);
    // cout << "\n";
    // printNto1(10);
    // cout << "\n";

    // cout << firstOccurence(v, 0, 10, n);
    // cout << pw(10, 5);
    spell(69);
    return 0;
}
