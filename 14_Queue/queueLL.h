template <typename T>
class node
{
    T data;
    node *next;
    node(T d) data = d;
};

template <typename T>
class Queue
{
    node *front = NULL;
    node *back = NULL;

public:
    void enqueue(T d)
    {
        if (front == back and front == NULL)
        {
            node<T> *temp = new node<T>(d);
            temp->next = NULL;
            front = back = temp;
        }
    }
    void dequeue()
    {
    }
    T front()
    {
    }
    T back()
    {
    }
    void print()
    {
        cout << "The Queue\n";
        for (auto i : arr)
            cout << i << " ";
        cout << "\n";
    }
};