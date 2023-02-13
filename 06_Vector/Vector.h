template <typename T>
class Vector
{
    T *array;
    int cs, mx;

public:
    Vector(int maxsize = 1)
    {
        cs = 0;
        mx = maxsize;
        array = new T[mx];
    }

    void push(const T data)
    {
        if (cs == mx)
        {
            int *oldarray = array;
            mx = 2 * mx;
            array = new T[mx];
            for (int i = 0; i < cs; i++)
                array[i] = oldarray[i];
            delete[] oldarray;
        }
        array[cs] = data;
        cs++;
    }

    void pop()
    {
        if (cs >= 0)
            cs--;
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    T front()
    {
        return array[0];
    }

    T back()
    {
        return array[cs - 1];
    }

    T at(int i) const
    {
        return array[i];
    }

    int size() const
    {
        return cs;
    }

    int capacity() const
    {
        return mx;
    }

    T operator[](const int i) const
    {
        return array[i];
    }
};