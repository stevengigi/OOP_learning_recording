#include"Triangle.h"

double Triangle::perimeter(void)
{
    double answer=0;
    answer = sqrt(pow(_x.getIndex(0)-_y.getIndex(0),2)+pow(_x.getIndex(1)-_y.getIndex(1),2));

    double temp=(_x-_y).length();
    temp+=(_y-_z).length();
    temp+=(_z-_x).length();
    return temp;
}

double Triangle::area(void)
{
    double a,b,c,s;
    a=(_x-_y).length();
    b=(_y-_z).length();
    c=(_z-_x).length();
    s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

/*Triangle::Triangle()
{
}
Triangle::Triangle(MathVector x,MathVector y,MathVector z) :_x(x),_y(y),_z(z)
{
    // _x=x;
    // _y=y;
    // _z=z;
    // same as :_x(x),_y(y),_z(z)
}*/

Triangle::~Triangle()
{
    std::cout << "Triangle destructor\n";
}