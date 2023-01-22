#include "Polygon.h"
#include "Triangle.h"
#include <algorithm>

Polygon::Polygon()
{
    //_arr = nullptr;
    _num = 0;
}
Polygon::~Polygon()
{
    /*if (_arr != nullptr)
    {
        delete[] _arr;
    }*/

    std::cout << "polygon destructor\n";
}
/*
bool compare(const MathVector &a, const MathVector &b) // cannot do ->, const MathVector &c)
{
    MathVector ca = a - c;
    MathVector cb = b - c;
    return ((0.5 * (ca.getIndex(0) * cb.getIndex(1) -
                    cb.getIndex(0) * ca.getIndex(1))) >= 0.000);
}
*/
Polygon Polygon::CreatePolygonST(MathVector *arr, int num)
{
    MathVector x = centroid(arr, num);
    CCWBefore ccw(x);
    std::sort(arr, arr + num, ccw);
    // arr[0+num]
    return Polygon(arr, num);
}

Polygon::Polygon(MathVector *arr, int num)
{
    //_arr = new MathVector[num];
    _num = num;
    for (int i = 0; i < num; i++)
    {
        //_arr[i] = arr[i];
        _arr.push_back(arr[i]);
    }
    // orginally sort here
}
double Polygon::area(void)
{
    double result = 0;
    for (int i = 0; i < _arr.size() - 2; i++)
    {
        Triangle t(_arr[0], _arr[i + 1], _arr[i + 2]);
        result += t.area();
    }
    return result;
    // return -1;
}
double Polygon::perimeter(void)
{
    double tot = 0;
    for (int i = 0; i < _num - 1; i++)
    {
        tot += (_arr[i] - _arr[i + 1]).length();
    }
    tot += (_arr[_num - 1] - _arr[0]).length();
    return tot;
}
void Polygon::expand(double input)
{
    for (int i = 1; i < _arr.size(); i++)
    {
        _arr[i] = _arr[i] / (1/input); // have not define *, so use /
    }
}
