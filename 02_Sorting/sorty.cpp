#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

vector<int> bubblesort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - i; j++)
        {
            for (auto x : v)
                cout << x << " ";
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
            cout << endl;
        }
    }
    return v;
}

vector<int> insertionsort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int current = v[i], prev = i - 1;
        while (prev >= 0 and v[prev] > current)
        {
            v[prev + 1] = v[prev];
            prev -= 1;
        }
        v[prev + 1] = current;
    }
    return v;
}

vector<int> selectionsort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int min_pos = i;
        for (int j = i; j < v.size(); j++)
            if (v[j] < v[min_pos])
                min_pos = j;
        swap(v[min_pos], v[i]);
    }
    return v;
}

vector<int> countingsort(vector<int> &v)
{
    int m = *max_element(v.begin(), v.end());
    vector<int> freq(m + 1, 0);
    for (auto x : v)
        freq[x]++;
    int j = 0;
    for (int i = 0; i <= m; i++)
        while (freq[i] > 0)
        {
            v[j] = i;
            freq[i]--;
            j++;
        }
    return v;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = {5, 4, 3, 2, 1};
    // sort(v.begin(), v.end(), greater<int>());
    // reverse(v.begin(), v.end());

    vector<int> ans = bubblesort(v);
    // vector<int> ans = insertionsort(v);
    // vector<int> ans = selectionsort(v);
    // vector<int> ans = countingsort(v);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}
