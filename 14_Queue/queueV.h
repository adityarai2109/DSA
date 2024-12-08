#include <vector>
using namespace std;

template <typename T>
class Queue
{
    vector<T> arr;

public:
    void enqueue(T d)
    {
        vector<T> newArr;
        newArr.push_back(d);
        for (auto i : arr)
            newArr.push_back(i);
        arr = newArr;
    }
    void dequeue() { arr.pop_back(); }
    T front() { return arr.front(); }
    T back() { return arr.back(); }
    void print()
    {
        cout << "The Queue\n";
        for (auto i : arr)
            cout << i << " ";
        cout << "\n";
    }
};