#include "Triangle.h"

/*Triangle::Triangle()
{
}

Triangle::Triangle(MathVector x, MathVector y, MathVector z)
{
    _x = x;
    _y = y;
    _z = z;
}*/

double Triangle::area(void)
{
    double a, b, c, s;
    a = (_x - _y).length();
    b = (_y - _z).length();
    c = (_z - _x).length();
    s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimeter(void)
{
    /*double answer = 0;
    answer = sqrt(pow(_x.getIndex(0) - _y.getIndex(0), 2) +
                  pow(_x.getIndex(1) - _y.getIndex(1), 2));
    */
    double tmp = (_x - _y).length();
    tmp += (_y - _z).length();
    tmp += (_z - _x).length();
    return tmp;
    // length of _x and _y
}

Triangle::~Triangle()
{
    std::cout << "triangle destructor\n";
}

void Triangle::expand(double input)
{
    _y = _y / (1 / input); // have not define *, so use /
    _z = _z / (1 / input);
}