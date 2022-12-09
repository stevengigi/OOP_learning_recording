#include<iostream>
#include"HelloWorld.h"
#include"MathVector.h"
#include"length.h"

static int tmp=0;

void SetValue(const int& input ){ // effect of const -> const int tmp -> input
    tmp=input;
}

void SetValue(int&& input ){ // effect of const -> const int tmp -> input
    tmp=input;
}

int GetValue(){
    return tmp;
}

int &Value(){
    return tmp;
}

int main(){
    std::cout << print() << '\n';
    double arr1[2]={1,2};
    double arr2[3]={4,5};
    int dim=2;
    MathVector v1(dim,arr1);
    MathVector v2(2,arr2);
    // try catch...
    double result=dot(v1,v2);
    int i=10; //copy constructor
    // lvalue -> identity + move in(memory)
    // pass by reference
    // & -> lvalue reference
    int j=10;
    j=GetValue();
    std::cout << j <<std::endl;
    Value()=i;
    j=GetValue();
    std::cout << j <<std::endl;
    SetValue(10);
    int k=100;
    SetValue(k);
    // try removing const from operator =
    // MathVectorm,z,w;
    // m=z+w; // z + w = rvalue can input the operator'=' function
    // return by reference -> lvalue & rvalue

    // && -> rvalue reference
    return 0;
}


