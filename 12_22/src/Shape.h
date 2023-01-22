#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <type_traits>

/*template <typename T_IN>
class Expand
{
private:
    T_IN _item;

public:
    Expand(T_IN i, double input) : _item(i) 
    {
        // c
        if (std::is_same<T_IN, Circle<int>>::value)
        {
        }
        else if (std::is_same<T_IN, Triangle>::value)
        { // t
        }
        else
        { // p
        }
    };
    T_IN getItem(void)
    {
        return _item;
    }
};*/

// Base class
class Shape
{
private: // cannot be accessed by dervied class
    int tmp;

protected: // can be accessed by dervied class
    std::string _name;

public:
    Shape() : _name("nothing") { std::cout << "shape default constructor\n"; };
    Shape(std::string input) : _name(input) { std::cout << "shape constructor\n"; };
    virtual ~Shape() { std::cout << "shape destructor\n"; };
    virtual double area(void) = 0; // virtual + = 0 => pure virtual, no defintion
    virtual double perimeter(void) = 0;
    virtual void expand(double input) = 0;
    // virtual -> cannot initialize as an object
    // Shape s; <- initialize as an object
    virtual std::string getName(void)
    {
        return _name;
    };
};

// why it does not work?
/*std::string Shape::getName(void)
{
    return _name;
};*/

/*Shape::Shape()
{
}

Shape::~Shape()
{
}*/

#endif