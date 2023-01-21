#include"Circle.h"

/*Circle::Circle(MathVector c,double r){
    _center=c;
    _radius=r;
}
Circle::Circle(MathVector c,double r,std::string name){
    _center=c;
    _radius=r;
    _name=name;
}*/
double Circle::area(void){
    return _radius * _radius * M_PI;
}
double Circle::perimeter(void){
    return 2 * _radius * M_PI;
}
std::string Circle::getname(void){
    return "Circle::" + _name;
}
