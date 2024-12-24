#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
    size_t count;
    std::vector<T> data;
public:
    Stack()
    {
        count = 0;
    }

    Stack(const Stack& c)
    {
        data.clear();

        count = c.count;

        for (int i = 0; i < count; ++i)
        {
            data.push_back(c.data[i]);
        }
    }

    Stack& operator=(const Stack& c)
    {
        if (this != &c)
        {
            data = c.data;
        }
        return *this;
    }

    void push(const T val)
    {
        data.push_back(val);
        ++count;
    }

    void pop()
    {
        if (count > 0)
        {
            data.pop_back();
            --count;
        }
        else throw "Error: stack is empty";
    }

    T& top()
    {
        if (count > 0)
        {
            return data[count - 1];
        }
        else throw "Error: stack is empty";
    }

    size_t size()
    {
        return count;
    }

    bool empty()
    {
        return count == 0;
    }
};