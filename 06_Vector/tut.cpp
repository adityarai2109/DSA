#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Imp vector functions
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    // v.push_back(9);
    // v.pop_back();
    cout << v.size() << " " << v.capacity() << endl;

    // fill constructor
    vector<int> v1(10, 0);
    // for (auto i : v1){
    //     cout << i << "\n";
    // }

    // find in vector (Linear search)         SEARCHES FOR SUBSEQUENCE https://www.cplusplus.com/reference/algorithm/search/
    auto it = find(v.begin(), v.end(), 5);
    // auto it = find(v.begin(), v.end(), 100);
    if (it != v.end())
        cout << "Index " << (it - v.begin()); // index
    else
        cout << "Absent";
    cout << "\n";
    cout << *lower_bound(v.begin(), v.end(), 6) << "\n";
    cout << *upper_bound(v.begin(), v.end(), 2) << "\n";
    cout << binary_search(v.begin(), v.end(), 2);
    return 0;
}
