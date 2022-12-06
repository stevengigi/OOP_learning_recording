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
        _arr=new double[_dim]; // be aware of memory leak , can be check with "valgrind"
                               // command : sudo apt install valgrind
        for(int i=0;i<_dim;i++){
            _arr[i]=arr[i];
        }
    }
    MathVector(int dim,double *arr){
        std::cout << "constructor" <<std::endl;
        init(dim,arr);
    }
    MathVector(const MathVector &input){ // copy constructor,pass by reference('&'):avoid copy
        // this is a pointer , pointing to object itself
        // this->_dim = input._dim; // MathVector &input 跟 class MathVector 物件一樣的話，可以取得private data
        // this->_arr= new double[this->_dim];
        // for(int i=0;i<_dim;i++){
        //     this->_arr[i]=input._arr[i];
        // }
        std::cout << "copy constructor" <<std::endl;
        init(input._dim,input._arr);

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
        std::cout << "copy assignment" << std::endl;
        if(this!= &input) // this is a pointer(address)
        {                  // '&' address of operator
            if(this->_arr!=nullptr){ // delete original data to avoid memory leak
                delete[] this->_arr;
            }
            init(input._dim,input._arr);
        }

        return *this;
    }
    // v2+v3 -> input = v3 , function is v2
    MathVector operator+(const MathVector &input){
        double *tmp=new double[input.getDim()];

        for(int i=0;i<input.getDim();i++){
            tmp[i]=this->_arr[i]+input._arr[i];
        }

        return MathVector(input.getDim(),tmp); // no copy constructor , <- compiler copy elison
        // no copy constructor cout ， 回傳一個物件 是一個compiler的加速(by reference)

    }
    MathVector operator/(const MathVector &input){
        double *tmp=new double[input.getDim()];

        for(int i=0;i<input.getDim();i++){
            tmp[i]=this->_arr[i]/input._arr[i];
        }

        return MathVector(input.getDim(),tmp); // no copy constructor , <- compiler copy elison
        // no copy constructor cout ， 回傳一個物件 是一個compiler的加速(by reference)

    }
    bool operator>(const MathVector &input){
        return this->length() > input.length();
    }
    bool operator<(const MathVector &input){
        return this->length() < input.length();
    }
    ~MathVector(){ // destructor
        std::cout << "destructor" << std::endl;
        delete[] _arr; // means _arr is "a pointer to array"
    }
    std::string toString(){
        std::string tmp="Dim: ";
        tmp+=std::to_string(_dim);
        tmp+=", location is [";
        for(int i=0;i<_dim;i++){
            tmp+=std::to_string(_arr[i]);
            if(i!=_dim-1){
                tmp+=",";
            }
        }
        tmp+="]";
        return tmp;
    }
    int getDim() const
    {
        return _dim;
    }
    double getIndex(int index) const // will not change data
    {
        return _arr[index];
    }
    double length() const
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