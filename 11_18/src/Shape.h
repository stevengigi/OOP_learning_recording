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
    Shape(std::string input) : _name(input){};
    // virtual 先定義好 function(basic func)
    virtual double area(void)=0; // virtual = no defintion
    virtual double perimeter(void)=0;
    // virtual -> can't initialize as an object
    // Shape s; // <- initialize as an object
};

#endif