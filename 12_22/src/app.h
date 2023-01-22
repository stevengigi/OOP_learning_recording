#ifndef APP_H
#define APP_H

#include "Shape.h"
#include <vector>
#include <algorithm>
#include "Circle.h"

// int a = 5, b = 6;
// exchange(a, b);
// a = 6, b = 5

template <typename T>
void exchange(T &a, T &b) // int a, int b
{
    T tmp = a; // int tmp;
    a = b;
    b = tmp;
}

template <typename T, typename C>
void exchange(T &a, T &b, C compare) // int a, int b
{
    if (compare(a, b))
    {
        T tmp = a; // int tmp;
        a = b;
        b = tmp;
    }
}

class App
{
private:
    std::vector<Shape *> _shapes;

public:
    App(){};
    ~App(){};
    void appAdd(Shape *input);
    void appSort(void);
    Shape *getIndex(int index);
    void exc(int i, int j);
};

void App::exc(int i, int j)
{
    exchange(_shapes[i], _shapes.at(j));
}

void App::appAdd(Shape *input)
{
    _shapes.push_back(input);
}

void App::appSort(void)
{
    std::sort(_shapes.begin(), _shapes.end(),
              [](Shape *a, Shape *b) { // Anonymous function, a.k.a lambda function
                  return a->area() < b->area();
              });
}

Shape *App::getIndex(int index)
{
    return _shapes[index];
}

#endif