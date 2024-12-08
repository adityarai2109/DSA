#include "bits/stdc++.h"
using namespace std;

void insertBottom(stack<int> &s, int d)
{
    if (s.empty())
    {
        s.push(d);
        return;
    }
    int x = s.top();
    s.pop();
    insertBottom(s, d);
    s.push(x);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    reverseStack(s);
    insertBottom(s, x);
}
void print(stack<int> t)
{
    while (!t.empty())
    {
        cout << t.top() << "\n";
        t.pop();
    }
    cout << "\n";
}

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here
    vector<long long> ans(n, -1);
    stack<long long> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
            s.pop();
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    print(s);
    reverseStack(s);
    print(s);
    return 0;
}
