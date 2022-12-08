#ifndef  MATH_VECTOR//保護自我的功能 (to avoid redefinition)
#define  MATH_VECTOR

#include<cmath>
#include <string>
class MathVector
{  // class name equals to file is better
private:
    int _dim;
    double *_arr;

public:

    MathVector();
    // data(input),text(source code),stack(variable),heap(dynamic memory)
    void init(int dim,double *arr);
    MathVector(int dim,double *arr);
    MathVector(const MathVector &input) : MathVector(input._dim,input._arr){};
    MathVector(MathVector &&input);                                             //move constructor
    MathVector& operator=(const MathVector &input);
    MathVector operator+(const MathVector &input);
    MathVector operator-(const MathVector &input);
    MathVector operator/(const MathVector &input);
    bool operator>(const MathVector &input);
    bool operator<(const MathVector &input);
    ~MathVector();
    std::string toString();
    int getDim() const ;
    double getIndex(int index) const ;// will not change data
    double length() const;
    void multiply(double a);
};

#endif