#ifndef LENGTH //第一次進來未被define 所以會define"LENGTH"，第二次 include 的話，就不會再進入了(avoid redefinition)
#define LENGTH

#include<cmath>
#include"MathVector.h"
using namespace std;

double length(double x,double y){
    double i;
    // i= x*x +y*y;
    i=pow(x,2)+pow(y,2);
    return sqrt(i);
}

double length(double x,double y,double z){
    double i=0;
    i=pow(x,2)+pow(y,2)+pow(z,2);
    return sqrt(i);
}

double length(double *arr,int dim){ // or double arr[]
    double sum=0;
    for(int i=0;i<dim;i++){
        sum+=pow(arr[i],2);
    }
    return sqrt(sum);
}
// function overloading
double length(MathVector m){
    double sum=0;
    for(int i=0;i<m.getDim();i++){
        sum+=pow(m.getIndex(i),2);
    }
    return sqrt(sum);
}
double dot(MathVector v1,MathVector v2){
    if(v1.getDim()!=v2.getDim()){
        // return -1; Maybe Error,not good
        throw  std::string("Undefined");
    }
    double sum=0;
    for(int i=0;i<v1.getDim();i++){
        sum+=v1.getIndex(i)*v2.getIndex(i);
    }
    return sum;
}
MathVector add(MathVector v1,MathVector v2){
    if(v1.getDim()!=v2.getDim()){
        throw std::string("Undefined");
    }
    double arr[v1.getDim()];
    for(int i=0;i<v1.getDim();i++){
        arr[i]=v1.getIndex(i)+v2.getIndex(i);
    }
    return MathVector(v1.getDim(),arr);
}

#endif