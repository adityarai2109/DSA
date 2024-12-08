#include "bits/stdc++.h"
using namespace std;
#define increment(n) n++;

void increment1(int &n) // by value
{
    n++;
}

void increment2(int *n) // by reference
{
    *n = *n + 1;
}

// int **dynamic2darray(int x, int y)
// {
//     int **array = new int *[x];
//     for (int i = 0; i < x; i++)
//     {
//         array[i] = new int[y];
//         delete[] array[i];
//     }
//     delete[] array;
//     return 0;
// }

int main()
{
    int x = 10;
    // cout << &x << "\n";          Hex address
    // cout << *(&x) << "\n";       10

    int *p = 0; // NULL  nullptr

    int n = 0;
    increment(n);
    increment1(n);
    increment2(&n);
    // cout << n;                   3

    // dynamic array
    int *arr = new int[x]; // new way of making array (heap memory)
    for (int i = 0; i < x; i++)
        cout << i << "-" << arr[i] << "\n";
    cout << *(arr + 5) << "\n";
    delete[] arr;
    cout << arr[5];
    return 0;
}
