#include <iostream>

using namespace std;

class TestFriendClass
{
public:
    // 默认的构造函数
    TestFriendClass()
    {
        cout << "默认调用的构造函数TestFriendClass()";
    }

    TestFriendClass(int a, int b)
    {
        int x = a;
        int y = b;
        cout << "x: " << x << "," << "y: " << y << "," << "x+y: " << x + y;
    }

    // 普通成员函数
    int sum()
    {
        return x * y;
    }

    friend int sumxy(TestFriendClass &obj);

private:
    int x;
    int y;
};

int sumxy(TestFriendClass &obj)
{
    return obj.x + obj.y;
}

int main()
{
    TestFriendClass obja;
}