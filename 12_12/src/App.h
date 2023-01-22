#ifndef APP_H
#define APP_H
#include"Shape.h"
#include<vector>
#include<algorithm>

template <typename T>

void exchange(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<typename T,typename C>
void exchange(T &a,T &b,C compare){
    if(compare(a,b)){
        T temp=a;
        a=b;
        b=temp;
    }
}

class App{

private:
    std::vector<Shape*> _shapes;
public:
    App(){};
    ~App(){};
    void appAdd(Shape *input);
    void sort(void);
    Shape* getIndex(int index);
    void exchange(int i,int j);
};

void App::exchange(int i,int j){
    exchange(_shapes[i],_shapes[j]);
}

void App::appAdd(Shape *input)
{
    _shapes.push_back(input);
}
void App::sort(void){
    std::sort(_shapes.begin(),_shapes.end(),[](Shape *a,Shape *b){
        return a->area() < b->area();
    }); // Anonymous fucntion , a.k.a lambda function
}
Shape* App::getIndex(int index)
{
    return _shapes[index]->area();
}
#endif