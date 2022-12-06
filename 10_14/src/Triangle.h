#ifndef TRANGLE_H
#define TRANGLE_H
#include"MathVector.h"
class Triangle
{
private:
    MathVector _x,_y,_z;
public:
    Triangle(MathVector x,MathVector y,MathVector z);
    ~Triangle();
    double area(void);
    double primeter(void);
};

Triangle::Triangle(MathVector x,MathVector y,MathVector z)
{
    _x=x;
    _y=y;
    _z=z;
}

Triangle::~Triangle()
{
}

Triangle::area()
{

}

#endif