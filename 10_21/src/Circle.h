#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include"MathVector.h"
class Circle
{
private:
    MathVector _center;
    double _radius;
public:
    Circle()=default;
    ~Circle();
    Circle(MathVector c,double r);
    double area(void);
    double perimeter(void);

};

#endif