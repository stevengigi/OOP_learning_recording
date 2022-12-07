#ifndef TRANGLE_H
#define TRANGLE_H
#include"MathVector.h"
class Triangle
{
private:
    MathVector _x,_y,_z;
public:
    Triangle()=default; //default constructor
    Triangle(MathVector x,MathVector y,MathVector z) : _x(x),_y(y),_z(z) {};
    Triangle(const Triangle& input)=delete; //avoid using copy constructor
    ~Triangle();                            // destructor should not delete
    double area(void);
    double primeter(void);
};


double Triangle::primeter(void)
{
    double answer=0;
    answer = sqrt(pow(_x.getIndex(0)-_y.getIndex(0),2)+pow(_x.getIndex(1)-_y.getIndex(1),2));

    double temp=(_x-_y).length();
    temp+=(_y-_z).length();
    temp+=(_z-_x).length();
    return temp;
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
}


#endif