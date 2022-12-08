#ifndef POLYGON_H
#define POLYGON_H
#include"MathVector.h"
#include"Shape.h"
class POLYGON_H : public Shape
{
private:
    MathVector *_arr;
    int _num;
public:
    Polygon();
    ~Polygon();
    Polygon(MathVector *arr,int num);
    double area(void) override;
    double perimeter(void) override;
};
#endif