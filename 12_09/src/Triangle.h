#ifndef TRANGLE_H
#define TRANGLE_H
#include"MathVector.h"
#include"Shape.h"
class Triangle : public Shape
{
private:
    MathVector _x,_y,_z;
public:
    Triangle()=default; //default constructor
    Triangle(MathVector &x,MathVector &y,MathVector &z) : _x((x)),_y((y)),_z((z)){
        std::cout << "lvalue &" << std::endl;
    };
    Triangle(MathVector&& x,MathVector&& y,MathVector&& z) : _x(std::move(x)),_y(std::move(y)),_z(std::move(z)) {
        std::cout << "rvalue &&" << std::endl;
    };
    Triangle(const Triangle& input)=delete; //avoid using copy constructor
    ~Triangle() override;                            // destructor should not delete
    double area(void) override;
    double perimeter(void) override;
};





#endif