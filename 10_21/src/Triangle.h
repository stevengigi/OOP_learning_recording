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
    double perimeter(void);
};





#endif