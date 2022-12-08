#ifndef POLYGON_H
#define POLYGON_H
#include"MathVector.h"

class POLYGON_H
{
private:
    MathVector *_arr;
    int _num;
public:
    Polygon();
    ~Polygon();
    Polygon(MathVector *arr,int num);
    double area(void);
    double perimeter(void);
};
#endif