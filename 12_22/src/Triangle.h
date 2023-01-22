#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "MathVector.h"
#include <cmath>
#include "Shape.h"
class Triangle : public Shape
{
private:
    MathVector _x, _y, _z;

public:
    Triangle() = default;
    Triangle(const MathVector &x, const MathVector &y, const MathVector &z) : _x(x), _y(y), _z(z) // same as _x = x
    {
        std::cout << "lvalue &" << std::endl;
    };
    Triangle(MathVector &&x, MathVector &&y, MathVector &&z) : _x((MathVector &&) x), _y(std::move(y)), _z(std::move(z))
    {
        std::cout << "rvalue &&" << std::endl;
    };
    Triangle(const Triangle &input) = delete; // avoid using copy constructor
    ~Triangle() override;                              // destructor shuold not delete
    double area(void) override;
    double perimeter(void) override;
    void expand(double input) override;
};

#endif