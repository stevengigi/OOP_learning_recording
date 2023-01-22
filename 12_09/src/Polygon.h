#ifndef POLYGON_H
#define POLYGON_H
#include"MathVector.h"
#include<cmath>
#include"Shape.h"
class Polygon;
class PolygonFactory;

static Polygon CreatePolygon(MathVector *arr,int num){
    MathVector x = centroid(arr,num);
    CCWBefore ccw(x);
    std::sort(arr,arr+num,ccw); //ccw find operator ()
    return Polygon(arr,num);
}

class Polygon : public Shape
{
    friend class PolygonFactory;
    friend Polygon CreatePolygon(MathVector *arr,int num);
private:
    std::vector<MathVector*> _arr;
    int _num;
    MathVector c;
    Polygon(MathVector *arr,int num);

public:
    Polygon();
    ~Polygon() override;

    // TBF static Polygon CreatePolygon(MathVector *arr,int num);
    double area(void) override;
    double perimeter(void) override;
    // MathVector getCentroid();
    friend bool compare(const MathVector &a,const MathVector &b); //允許直接拿取private的資料
};


class PolygonFactory{
public:
    Polygon CreatePolygon(MathVector *arr,int num){
        MathVector x = centroid(arr,num);
        CCWBefore ccw(x);
        std::sort(arr,arr+num,ccw); //ccw find operator ()
        return Polygon(arr,num);
    }
    Polygon CreatePolygonPtr(MathVector *arr,int num){
        MathVector x = centroid(arr,num);
        CCWBefore ccw(x);
        std::sort(arr,arr+num,ccw); //ccw find operator ()
        return Polygon(arr,num);
    }
};


#endif