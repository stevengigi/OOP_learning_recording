#include"Polygon.h"

Polygon::Polygon()
{
    _arr=nullptr;
    _num=0;
}
Polygon::~Polygon(){
    if(_arr!=nullptr){
        delete[] _arr;
    }
}

MathVector centroid(MathVector *arr,int num){
    MathVector c;
    for(int i=0;i<num;i++){
        c=c+arr[i];
    }
    return (c/num);
}
bool compare(const MathVector &a,const MathVector &b){
    MathVector ca=a-c;
    MathVector cb=b-c;
    return (0.5*(ca.getIndex(0)*cb.getIndex(1)-ca.getIndex(1)*cb.getIndex(0)))>=0.000;
}
Polygon::Polygon(MathVector *arr,int num)
{
    // _arr=new MathVector[num];

    _num=num;
    for(int i=0;i<num;i++){
        // _arr[i]=arr[i]; //MathVector operator'='
        _arr.push_back(arr[i]);
    }
    c = centroid();
    std::sort(_arr.begin(),_arr.end(),compare);
}

double Polygon::area(void)
{
    return 0;
}

double Polygon::perimeter(void)
{
    double total=0;
    for(int i=0;i<_num-1;i++){
        total+=(_arr[i] - _arr[i+1]).length();
    }
    total+=(_arr[_num-1] - _arr[0]).length();
    return total;
}
