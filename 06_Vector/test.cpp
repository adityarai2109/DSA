#include "bits/stdc++.h"
#include "Vector.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // My Vector.h
    Vector<int> v(2);
    // Vector<string> s;      using template
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);
    v.pop();
    cout << "------------Custom Vector.h-------------\n";
    cout << v.size() << " " << v.capacity() << "\n";
    cout << v.front() << " " << v.back() << " ";
    cout << v.at(0) << " " << v[2] << "\n";
    cout << v.isEmpty() << "\n";
    cout << "----------------------------------------\n";

    return 0;
}
