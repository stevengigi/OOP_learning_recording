#ifndef  MATH_VECTOR//保護自我的功能 (to avoid redefinition)
#define  MATH_VECTOR

#include<cmath>

class MathVector
{  // class name equals to file is better
private:
    int _dim;
    double *_arr;

public:
    // Constructor : 建立物件
    MathVector(){ //default Constructor
        _dim=0;
        _arr=NULL;
    }
    // data(input),text(source code),stack(variable),heap(dynamic memory)
    MathVector(int dim,double *arr){
        _dim=dim;
        _arr=new double[_dim]; // be aware of memory leak , can be check with "valgrind"
                               // command : sudo apt install valgrind
        for(int i=0;i<_dim;i++){
            _arr[i]=arr[i];
        }

        // _arr=arr; error ,
        // 1 - if address of arr free ,MathVector _arr will be error.
        // 2- if the data of arr is changed , MathVector _arr will be changed too.
        // MathVector needs _arr that has own address and data.
    }
    MathVector(const MathVector &input){ // copy constructor,pass by reference('&'):avoid copy
        // this is a pointer , pointing to object itself
        this->_dim = input._dim; // MathVector &input 跟 class MathVector 物件一樣的話，可以取得private data
        this->_arr= new double[this->_dim];
        for(int i=0;i<_dim;i++){
            this->_arr[i]=input._arr[i];
        }
        std::cout << "copy constructor" <<std::endl;
    }
    ~MathVector(){ // destructor
        delete[] _arr; // means _arr is "a pointer to array"
    }
    int getDim() const
    {
        return _dim;
    }
    double getIndex(int index) const // will not change data
    {
        return _arr[index];
    }
    double length()
    {
        double sum=0;
        for(int i=0;i<_dim;i++){
            sum+=pow(_arr[i],2);
        }
        return sum;
    }
    void multiply(double a){
        for(int i=0;i<_dim;i++){
            _arr[i]*=a;
        }
    }
};

#endif