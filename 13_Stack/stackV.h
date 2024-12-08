#include <vector>
using namespace std;

template <typename T>
class Stack
{
    vector<T> arr;

public:
    void push(T d)
    {
        arr.push_back(d);
    }
    void pop()
    {
        arr.pop_back();
    }
    bool top()
    {
        int n = arr.size() - 1;
        return arr[n];
    }
    void isEmpty()
    {
        return arr.size() == 0;
    }
};