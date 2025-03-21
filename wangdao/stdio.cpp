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

    string line;
    cin >> line;
    cout << "Line:" << line << endl;
}

int main(void)
{
    test0();
    return 0;
}