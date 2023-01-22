#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

class MathVector
{
private:
    int _dim;
    double *_arr; // uncertain size array
    std::vector<double> _arrV;

public:
    // Constructor
    MathVector(); // default constructor
    void init(int dim, double *arr);
    // MathVector(int dim, double *arr);
    // MathVector(int dim, int *arr);
    MathVector(int dim, void *arr);
    MathVector(const MathVector &input) : MathVector(input._dim, input._arr){}; // copy constructor, pass by reference
    MathVector(MathVector &&input) noexcept;                                    // move constructor
    ~MathVector();                                                              // destructor
    MathVector &operator=(const MathVector &input);                             // copy assignment, assignment operator overloading
    MathVector &operator=(MathVector &&input);                                  // move assignment, transferring a temporary object to an existing object.
    MathVector operator+(const MathVector &input) const;                        // operator overloadding
    MathVector operator-(const MathVector &input) const;                        // operator overloadding
    MathVector operator/(const MathVector &input) const;                        // operator overloadding
    MathVector operator/(int input) const;
    // a = b + c; -> add(b, c);
    bool operator>(const MathVector &input);
    bool operator<(const MathVector &input);
    friend std::ostream &operator<<(std::ostream &output, const MathVector &m) // TBD
    {
        std::string tmp = "";
        std::stringstream ss;
        output << m._dim << std::endl;
        for (int i = 0; i < m._dim; i++)
        {
            output << m._arr[i] << ",";
        }
        output << ss.str();
        tmp = ss.str();
        return output;
    }
    friend std::istream &operator>>(std::istream &input, MathVector &m) // TBD
    {
        // not using friend
        // int tmp = 0;
        // input >> tmp;
        // m.setDim(tmp); 
        input >> m._dim;
        double *tmp = new double[m._dim];
        for (int i = 0; i < m._dim; i++)
        {
            input >> tmp[i];
        }
        // TBD -> check dim -> delete _arr + new _arr -> put tmp into _arr
        return input;
    }
    // MathVector m, n;
    // cout << m;
    // cin >> m;
    // n = m / 10;
    std::string toString();
    // getter
    int getDim() const;
    double getIndex(int i) const;
    double length() const;
    // double dot(MathVector v1){}
    void multiply(double a);
};

#endif
