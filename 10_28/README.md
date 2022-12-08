####  OOP 10/28

- static
    - static變數就是在載入程式後會主動配給記憶體給程式(僅一次)，後續無論實例化多少次，記憶體位置都一樣。

- understand lvalue rvalue
```c

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
```

- lvalue
    - identity + move in(memory)
    - '&' -> lvalue reference
```c
    int i=10;
    SetValue(i); // <- ok
    SetValue(10); // <- error (10 is rvalue)
    void SetValue(const int& input ){ // effect of const -> const int tmp -> input
        tmp=input;
    }
```
```c
    static tmp=0;
    Value()=10;
    // tmp=10;
    int &Value(){
        return tmp;
    }
```

- rvalue
    - a temporary object or subobject thereof, or a value that is not associated with an object
    - '&&' -> rvalue reference
```c
    // SetValue(10) is ok
    // 10 is rvalue
    void SetValue(int&& input ){
        tmp=input;
    }
```
- Triangle.cpp & Triangle.h change
```c
void TriangleTest::SetUp()  // 自己定義 SetUp
{
    double arr1[2]={0,0};
    double arr2[2]={3,0};
    double arr3[2]={0,4};
    // MathVector(2,arr1) is rvalue
    // 避免做多餘的動作(v1=MathVector(2,arr1))，再把v1傳入到Triangle裡，直接寫一個可以吃rvalue reference 的 funtion
    // 減少 malloc 記憶體的使用
    // v1=MathVector(2,arr1);
    // v2=MathVector(2,arr2);
    // v3=MathVector(2,arr3);
    t=Triangle(MathVector(2,arr1),MathVector(2,arr2),MathVector(2,arr3));
}

MathVector::MathVector(MathVector &&input){ // rvalue reference (move constructor)
    this->_dim=input._dim;
    this->_arr=input._arr;
    input._dim=0;
    input._arr=nullptr;
}
```
```c
    Triangle(MathVector&& x,MathVector&& y,MathVector&& z) : _x(std::move(x)),_y(std::move(y)),_z(std::move(z)) {};
    // function is changed to use rvalue input，use std::move call move constructor
```