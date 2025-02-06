#include <iostream>
#include "mytime2.h"

int main()
{
    using std::cout;
    using std::endl;
    Time weeding(4, 35);
    Time waxing(2, 40);
    Time total;
    Time diff;
    Time adjusted;

    cout << "wedding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing; // use operator+()
    total.Show();
    cout << endl;

    diff = weeding - waxing; // use operator-()
    cout << "diff = weeding - waxing time =";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;
    cout << "adjusted word time = ";
    adjusted.Show();
    cout << endl;

    return 0;
}