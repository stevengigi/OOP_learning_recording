#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include"MathVector.h"
#include"Shape.h"

class Circle: public Shape //Derived class (繼承後 virtual function 一定要做實體化的定義),public protected private all can be used for derived
{
private:
    MathVector _center;
    double _radius;
public:
    Circle()=default;
    ~Circle();
    Circle(MathVector c,double r) : _center(c),_radius(r) {};
    Circle(MathVector c,double r,std::string name) : _center(c),_radius(r) ,Shape(name) {};
    double area(void) override; //繼承過來的(override)
    double perimeter(void) override;

};

#endif