template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T d) data = d;
};

template <typename T>
class Stack
{
    Node<T> *top;

public:
    Stack() top = NULL;

    void push(T data)
    {
        Node<T> *n = new Node<T>(data);
        n->next = top;
        top = n;
    }

    void pop()
    {
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() return top == NULL;

    int Top() return top->data;
};