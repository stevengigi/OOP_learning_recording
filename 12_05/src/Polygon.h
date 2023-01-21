#ifndef POLYGON_H
#define POLYGON_H
#include"MathVector.h"
#include<cmath>
#include"Shape.h"
class Polygon : public Shape
{
private:
    std::vector<MathVector*> _arr;
    int _num;
    MathVector c;
public:
    Polygon();
    ~Polygon();
    Polygon(MathVector *arr,int num);
    double area(void) override;
    double perimeter(void) override;
    // MathVector getCentroid();
    friend bool compare(const MathVector &a,const MathVector &b); //允許直接拿取private的資料
};
#endif