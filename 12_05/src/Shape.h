#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>

//Base class
class Shape{

private:
    int tmp; //cannot be accessed by derived class

protected: //can be accessed by derived class
    std::string _name;

public:
    Shape():_name("nothing"){};
    Shape(std::string input) : _name(input){};
    // virtual 先定義好 function(basic func)
    virtual double area(void)=0; // virtual = + = 0 => pure virtual
    virtual double perimeter(void)=0;
    // virtual -> can't initialize as an object
    // Shape s; // <- initialize as an object
    virtual std::string getname(void){ //可以被繼承後被定義
        return _name;
    }
};
 // why it does not work
//  std::string Shape::getname(void)
// {
//     return _name;
// }

#endif