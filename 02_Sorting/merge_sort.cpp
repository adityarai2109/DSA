#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a < b) ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

template <typename T>
class MergeSort
{
public:
    void merge(vector<T> &array, T s, T m, T e)
    {
        int k1 = s, k2 = m + 1;
        vector<T> temp;
        while (k1 <= m and k2 <= e)
            (array[k1] < array[k2])
                ? temp.push_back(array[k1++])
                : temp.push_back(array[k2++]);
        while (k1 <= m)
            temp.push_back(array[k1++]);
        while (k2 <= e)
            temp.push_back(array[k2++]);
        for (int i = s, j = 0; i <= e; i++, j++)
            array[i] = temp[j];
    }

    void util(vector<T> &array, T s, T e)
    {
        if (s >= e)
            return;
        int m = s + (e - s) / 2;
        util(array, s, m);
        util(array, m + 1, e);
        merge(array, s, m, e);
    }

    void mergeSort(vector<T> &array)
    {
        int n = array.size();
        if (n == 0)
            return;
        util(array, 0, n - 1);
        // print(array);
    }

    void print(vector<T> &array)
    {
        for (T i : array)
            cout << i << " ";
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    MergeSort<int> S;
    S.mergeSort(v);

    return 0;
}
