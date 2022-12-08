#include<iostream>
#include"HelloWorld.h"
#include"MathVector.h"
#include"length.h"
int main(){
    std::cout << print() << '\n';
    double arr1[2]={1,2};
    double arr2[3]={4,5};
    int dim=2;
    MathVector v1(dim,arr1);
    MathVector v2(2,arr2);
    // try catch...
    double result=dot(v1,v2);
    return 0;
}
