#include"MathVector.h"
#include<cmath>

MathVector::MathVector(){ //default Constructor
    _dim=0;
    _arr=NULL;
}
// data(input),text(source code),stack(variable),heap(dynamic memory)
void MathVector::init(int dim,double *arr)
{
    _dim=dim;
    _arr=new double[_dim]; // be aware of memory leak , can be check with "valgrind"
                            // command : sudo apt install valgrind
    for(int i=0;i<_dim;i++){
        _arr[i]=arr[i];
        _arrV.push_back(arr[i]);
    }
}

MathVector::MathVector(int dim,double *arr) : MathVector()
{
    init(dim,arr);
}
// MathVector operator=(...) return by value;
// MathVector& operator=(...) return by reference;
MathVector& MathVector::operator=(const MathVector &input){ //copy assignment,assignment operator overloading
    // MathVector a ,b;
    // a=b;
    // a=a;

    // object-level compare (*this != input) int *a=new int(5) -> *a=5 , a=address;
    // address-level comparing (this!=&input)
    // 由於 this may have data (new double[]), we need to free original data to avoid memory leak
    // std::cout << "copy assignment" << std::endl;
    if(this!= &input) // this is a pointer(address)
    {                  // '&' address of operator
        if(this->_arr!=nullptr){ // delete original data to avoid memory leak
            delete[] this->_arr;
        }
        init(input._dim,input._arr);
    }

    return *this;
}
MathVector& MathVector::operator=(const MathVector &&input){
    if(this!=&input){
        this->_dim=std::move(input._dim);
        this->_arr=std::move(input._arr);
        // 做完move(rvalue becomes lvalue)，原本資料(rvalue)會被清空
    }
    return *this;
}
// v2+v3 -> input = v3 , function is v2
MathVector MathVector::operator+(const MathVector &input){
    double *tmp=new double[input.getDim()];

    for(int i=0;i<input.getDim();i++){
        tmp[i]=this->_arr[i]+input._arr[i];
    }

    /*std::vector<double>::iterator itr; //可以逐個訪問 container 的內容， is pointer
    int j=0;
    for(itr =_arrV.begin();itr <_arrV.end();itr++){ // reslove length problem(input._num)
        tmp[j]=(*itr)+input.getIndex(j);
        j+=1;
    }*/
    MathVector m =MathVector(input.getDim(),tmp);  //resolve memory leak
    delete[] tmp;
    return m;
    // return MathVector(input.getDim(),tmp); // no copy constructor , <- compiler copy elison
    // no copy constructor cout ， 回傳一個物件 是一個compiler的加速(by reference)

}
MathVector MathVector::operator-(const MathVector &input){
    double *tmp=new double[input.getDim()];

    for(int i=0;i<input.getDim();i++){
        tmp[i]=this->_arr[i]-input._arr[i];
    }
    MathVector m =MathVector(input.getDim(),tmp);
    delete[] tmp;
    return m; // no copy constructor , <- compiler copy elison
    // no copy constructor cout ， 回傳一個物件 是一個compiler的加速(by reference)

}
MathVector MathVector::operator/(const MathVector &input){
    double *tmp=new double[input.getDim()];

    for(int i=0;i<input.getDim();i++){
        tmp[i]=this->_arr[i]/input._arr[i];
    }
    MathVector m =MathVector(input.getDim(),tmp);
    delete[] tmp;
    return m; // no copy constructor , <- compiler copy elison
    // no copy constructor cout ， 回傳一個物件 是一個compiler的加速(by reference)

}
bool MathVector::operator>(const MathVector &input){
    return this->length() > input.length();
}
bool MathVector::operator<(const MathVector &input){
    return this->length() < input.length();
}
MathVector::MathVector(MathVector &&input){ // rvalue reference (move constructor)
    this->_dim=input._dim;
    this->_arr=input._arr;
    input._dim=0;
    input._arr=nullptr;
}
MathVector::~MathVector(){ // destructor
    // std::cout << "destructor" << std::endl;
    delete[] _arr; // means _arr is "a pointer to array"
}
std::string MathVector::toString(){
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
int MathVector::getDim() const
{
    return _dim;
}
double MathVector::getIndex(int index) const // will not change data
{
    return _arr[index];
}
double MathVector::length() const
{
    double sum=0;
    for(int i=0;i<_dim;i++){
        sum+=pow(_arr[i],2);
    }
    return sqrt(sum);
}
void MathVector::multiply(double a){
    for(int i=0;i<_dim;i++){
        _arr[i]*=a;
    }
}