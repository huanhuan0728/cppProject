#include <iostream>
using namespace std;

// 定义一个模版类，表示一个简单的栈
template <typename T>
class Stack
{
private:
    T *arr;
    int capacity;
    int top;

public:
    Stack(int size)
    {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    void push(T value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    T pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return T(); // 返回T类型的默认值
        }
        return arr[top--];
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    cout << "Popped element: " << intStack.pop() << endl;

    Stack<double> doubleStack(5);
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    cout << "Popped value: " << doubleStack.pop() << endl;

    return 0;
}