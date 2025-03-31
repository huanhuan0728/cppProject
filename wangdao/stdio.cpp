#include <iostream>
using namespace std;

void printStreamStatus(istream &is)
{
    cout << " is's goodbit:" << is.good() << endl
         << "is's badbit: " << is.bad() << endl
         << "is's eofbit: " << is.eof() << endl;
}

void test0()
{
    int number = -1;
    printStreamStatus(cin);

    cin >> number;
    cout << "number: " << number << endl;
    printStreamStatus(cin);

    string line; // 希望等待输入
    // 输入流运算符默认使用空格、\t进行分隔
    cin >> line;
    cout << "Line:" << line << endl;
}

int read_integer_number()
{
    int number = -1;
    while (cin >> number, !cin.eof())
    {
        if (cin.bad())
        {
            cout << "cin has broken!" << endl;
        }
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please input a valid interger number" << endl;
        }
        else
        {
            cout << "Number" << number << endl;
            return number;
        }
    }
}

int main(void)
{
    test0();
    return 0;
}