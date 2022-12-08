#include"Circle.h"

Circle::Circle(MathVector c,double r){
    _center=c;
    _radius=r;
}
double Circle::area(void){
    return _radius * _radius * M_PI;
}
double Circle::perimeter(void){
    return 2 * _radius * M_PI;
}
