#ifndef POLYGON_H
#define POLYGON_H
#include <algorithm>
#include "MathVector.h"
#include "Shape.h"

class Polygon;
class PolygonFactory;
static Polygon CreatePolygonSF(MathVector *arr, int num);

static MathVector centroid(MathVector *arr, int num)
{
    MathVector c;
    for (int i = 0; i < num; i++)
    {
        c = c + arr[i];
        // int i, j = 10, k = 0;
        // k = i + j; -> k = j;
        // k -> 10
    }
    return (c / num); // TBD friend function
}

class CCWBefore
{
private:
    MathVector centroid;

public:
    CCWBefore(MathVector c)
    {
        centroid = c;
    }
    bool operator()(const MathVector &a, const MathVector &b)
    {
        MathVector ca = a - centroid;
        MathVector cb = b - centroid;
        return ((0.5 * (ca.getIndex(0) * cb.getIndex(1) -
                        cb.getIndex(0) * ca.getIndex(1))) >= 0.000);
    }
};

class Polygon : public Shape
{
    friend Polygon CreatePolygonSF(MathVector *arr, int num);
    friend class PolygonFactory;
    // friend bool compare(const MathVector &a, const MathVector &b);
private:
    // MathVector *_arr;
    std::vector<MathVector> _arr;
    int _num;
    Polygon(MathVector *arr, int num);

public:
    Polygon();
    ~Polygon() override;
    // 1. Make sure the items of arr is clockwise, counter-clockwise
    // 2. Constructor
    // 3. Factory (Simple Factory)
    static Polygon CreatePolygonST(MathVector *arr, int num);
    double perimeter(void) override;
    double area() override;
    MathVector getCentriod();
    void expand(double input) override;
};

static Polygon CreatePolygonSF(MathVector *arr, int num)
{
    MathVector x = centroid(arr, num);
    CCWBefore ccw(x);
    std::sort(arr, arr + num, ccw);
    // arr[0+num]
    return Polygon(arr, num);
} // simple factory

class PolygonFactory
{
public:
    Polygon CreatePolygon(MathVector *arr, int num)
    {
        MathVector x = centroid(arr, num);
        CCWBefore ccw(x);
        std::sort(arr, arr + num, ccw);
        // arr[0+num]
        return Polygon(arr, num);
    };
    Polygon *CreatePolygonPtr(MathVector *arr, int num)
    {
        MathVector x = centroid(arr, num);
        CCWBefore ccw(x);
        std::sort(arr, arr + num, ccw);
        // arr[0+num]
        return new Polygon(arr, num);
    };
};

#endif
