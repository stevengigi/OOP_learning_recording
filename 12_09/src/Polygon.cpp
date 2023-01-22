#include"Polygon.h"
#include"Triangle.h"

Polygon::Polygon()
{
    _arr=nullptr;
    _num=0;
}
Polygon::~Polygon(){
    if(_arr!=nullptr){
        delete[] _arr;
    }
    std::cout << "polygon destructor\n";
}

MathVector centroid(MathVector *arr,int num){
    MathVector c; // initial dim=0 -> c+arr[i] ->operator(+) error ， because c=this->_arr[i] is null
    for(int i=0;i<num;i++){
        c = arr[i] + c;
        // int i=0,j=10,k=0
        // k = i + j;
        // k = 10
        // if int i->k!=10
    }
    return (c/num);
}
/*bool compare(const MathVector &a,const MathVector &b){
    MathVector ca=a-c;
    MathVector cb=b-c;
    return (0.5*(ca.getIndex(0)*cb.getIndex(1)-ca.getIndex(1)*cb.getIndex(0)))>=0.000;
}*/

class CCWBefore{
private:
    MathVector centroid;
public:
    CCWBefore(MathVector c){
        centroid = c;
    }
    // ()被overload
    bool operator()(const MathVector &a,const MathVector &b){ //相當於 bool compare over
        MathVector ca=a-centroid;
        MathVector cb=b-centroid;
        return (0.5*(ca.getIndex(0)*cb.getIndex(1)-ca.getIndex(1)*cb.getIndex(0)))>=0.000;
    }
}

Polygon Polygon::CreatePolygon(MathVector *arr,int num){
    MathVector x = centroid(arr,num);
    CCWBefore ccw(x);
    std::sort(arr,arr+num,ccw); //ccw find operator ()
    return Polygon(arr,num);
}

Polygon::Polygon(MathVector *arr,int num)
{
    // _arr=new MathVector[num];

    _num=num;
    for(int i=0;i<num;i++){
        // _arr[i]=arr[i]; //MathVector operator'='
        _arr.push_back(arr[i]);
    }
    // MathVector x = centroid(arr,num);
    // CCWBefore ccw(x);
    // std::sort(_arr.begin(),_arr.end(),ccw); //ccw find operator ()
}

double Polygon::area(void)
{
    double area=0;
    for(int i=0;i<_arr.size-2;i++){
        Triangle t(_arr[i],_arr[i+1],_arr[i+2]);
    }
    return result;
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
