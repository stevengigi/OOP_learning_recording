#include<cmath>

class MathVector
{  // class name equals to file is better
private:
    int _dim;
    double *_arr;

public:
    // Constructor : 建立物件
    MathVector(){ //default Constructor

    }
    MathVector(int dim,double *arr){
        _dim=dim;
        _arr=new double[_dim];
        for(int i=0;i<_dim;i++){
            _arr[i]=arr[i];
        }

        // _arr=arr; error ,
        // 1 - if address of arr free ,MathVector _arr will be error.
        // 2- if the data of arr is changed , MathVector _arr will be changed too.
        // MathVector needs _arr that has own address and data.
    }
    int getDim(){
        return _dim;
    }
    double getIndex(int index){
        return _arr[index];
    }
};