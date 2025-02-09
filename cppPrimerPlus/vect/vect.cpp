#include <cmath>
#include "vect.h"

using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR
{
    const double Rad_to_deg = 45.0;
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    // public methods
    Vector::Vector() // default constructor
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

} // namespace VECTOR
