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
    void init(int dim,double *arr){
        _dim=dim;
        if(_arr!=NULL){
            delete[] _arr;
        }
        _arr=new double[_dim]; // be aware of memory leak , can be check with "valgrind"
                               // command : sudo apt install valgrind
        for(int i=0;i<_dim;i++){
            _arr[i]=arr[i];
        }
    }
    MathVector(int dim,double *arr){
        init(dim,arr);
    }
    MathVector(const MathVector &input){ // copy constructor,pass by reference('&'):avoid copy
        // this is a pointer , pointing to object itself
        // this->_dim = input._dim; // MathVector &input 跟 class MathVector 物件一樣的話，可以取得private data
        // this->_arr= new double[this->_dim];
        // for(int i=0;i<_dim;i++){
        //     this->_arr[i]=input._arr[i];
        // }
        init(input._dim,input._arr);
        std::cout << "copy constructor" <<std::endl;
    }
    // MathVector operator=(...) return by value;
    // MathVector& operator=(...) return by reference;
    MathVector& operator=(const MathVector &input){ //copy assignment,assignment operator overloading
        // MathVector a ,b;
        // a=b;
        // a=a;

        // object-level compare (*this != input) int *a=new int(5) -> *a=5 , a=address;
        // address-level comparing (this!=&input)
        // 由於 this may have data (new double[]), we need to free original data to avoid memory leak
        if(this!= &input) // this is a pointer(address)
        {                  // '&' address of operator
            init(input._dim,input._arr);
        }
        std::cout << "copy assignment" << std::endl;
        return *this;
    }
    // v2+v3 -> input = v3 , function is v2
    MathVector operator+(const MathVector &input){
        double *tmp=new double[input.getDim()];

        for(int i=0;i<input.getDim();i++){
            tmp[i]=this->_arr[i]+input._arr[i];
        }

        return MathVector(input.getDim(),tmp);
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