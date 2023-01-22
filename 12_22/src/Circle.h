#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include "MathVector.h"

template <typename K_ID>
class Circle : public Shape // Dervied clas, (public, protected, private)
{
private:
    MathVector _center;
    double _radius;
    K_ID _id;

public:
    Circle() = default;
    ~Circle() override { std::cout << "circle destructor\n"; };
    Circle(K_ID i, MathVector c, double r) : _id(i), _center(c), _radius(r) { std::cout << "circle constructor 1\n"; };
    Circle(K_ID i, MathVector c, double r, std::string name) : _id(i), _center(c), _radius(r), Shape(name) { std::cout << "circle constructor 2\n"; };
    double area(void) override;
    double perimeter(void) override;
    std::string getName(void) override;
    void expand(double input) override;
};
#endif