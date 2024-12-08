#include "bits/stdc++.h"
using namespace std;
#define mod 1e9 + 7
#define INF 1000000000000000003

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    pq.push(6);
    cout << pq.top();
    return 0;
}