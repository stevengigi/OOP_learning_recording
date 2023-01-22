#include "MathVector.h"

// Constructor
MathVector::MathVector() // default constructor
{
    _dim = 0;
    _arr = NULL;
}
void MathVector::init(int dim, double *arr)
{
    _dim = dim;
    _arr = new double[_dim]; // be aware of memory leak
                             // can be check with valgrind
                             // sudo apt install valgrind
    // data, text, stack, heap
    for (int i = 0; i < _dim; i++)
    {
        _arr[i] = arr[i];
        _arrV.push_back(arr[i]);
    }
}
MathVector::MathVector(int dim, void *arr) : MathVector() // inline function call
{
    // std::cout << "constructor" << std::endl;
    init(dim, (double *)arr);
}

// MathVector::MathVector(const MathVector &input) : MathVector(input._dim, input._arr) // copy constructor, pass by reference
// {
//     std::cout << "copy constructor" << std::endl;
//     // init(input._dim, input._arr);
//     /*
//     //_dim = input.getDim();
//     this->_dim = input._dim;
//     this->_arr = new double[_dim];
//     for (int i = 0; i < _dim; i++)
//     {
//         this->_arr[i] = input._arr[i];
//     }
//     // this is a pointer, pointing to object itself
//     */
// }

MathVector::MathVector(MathVector &&input) noexcept
{
    //std::cout << "move constructor" << std::endl;

    this->_dim = input._dim;
    this->_arr = input._arr;

    input._dim = 0;
    input._arr = nullptr;
}

MathVector::~MathVector() // destructor
{
    delete[] _arr; // [] means _arr is "a pointer to array"
}
MathVector &MathVector::operator=(const MathVector &input) // copy assignment, assignment operator overloading
{
    // MathVector a, b;
    // a = b;
    // a = a; -> avoid
    // object-level comparing (*this != input) not prepare yet
    // adress-level comparing
    if (this != &input) // this is a pointer (address)
                        // int *a = new int(5); *a -> 5, a -> address; *a = 6;
    {                   // & address of operator
        //std::cout << "copy assignment" << std::endl;
        if (this->_arr != nullptr) // nullptr or NULL ?
        {
            delete[] this->_arr;
        }
        init(input._dim, input._arr);
    }

    return *this;
}

MathVector &MathVector::operator=(MathVector &&input)
{
    //std::cout << "move assignment" << std::endl;

    if (this == &input)
    {
        return *this;
    }

    if (this->_arr != nullptr)
    {
        delete[] this->_arr;
    }

    this->_dim = input._dim;
    this->_arr = input._arr;

    input._arr = nullptr;

    return *this;
}

MathVector MathVector::operator+(const MathVector &input) const // operator overloadding
// a = b + c; -> add(b, c);
{
    if(this->_arr==nullptr || this->_dim==0){
        return MathVector(input);
        //return input; -> wrong
    }
    if(input._arr==nullptr || input._dim==0){
        return MathVector(*this);
    }

    double *tmp = new double[input.getDim()];
    for (int i = 0; i < input.getDim(); i++)
    {
        tmp[i] = this->_arr[i] + input._arr[i];
        //_arrV[i];
    }

    /*std::vector<double>::iterator itr;
    int j = 0;
    for (itr = _arrV.begin(); itr != _arrV.end(); itr++)
    {
        tmp[j] = (*itr) + input.getIndex(j);
        j += 1;
    }*/

    MathVector m = MathVector(input.getDim(), tmp);
    delete[] tmp;
    return m;
    // no copy constructior <- compiler copy elision
}
MathVector MathVector::operator-(const MathVector &input) const // operator overloadding
{
    if (this->_arr == nullptr || this->_dim == 0)
    {
        return MathVector(input);
        // return input; -> wrong
    }
    if (input._arr == nullptr || input._dim == 0)
    {
        return MathVector(*this);
    }
    
    double *tmp = new double[input.getDim()];
    for (int i = 0; i < input.getDim(); i++)
    {
        tmp[i] = this->_arr[i] - input._arr[i];
    }
    MathVector m = MathVector(input.getDim(), tmp);
    delete[] tmp;
    return m;
    // no copy constructior <- compiler copy elision
}
MathVector MathVector::operator/(const MathVector &input) const // operator overloadding
// a = b + c; -> add(b, c);
{
    double *tmp = new double[input.getDim()];
    for (int i = 0; i < input.getDim(); i++)
    {
        tmp[i] = this->_arr[i] / input._arr[i];
    }
    MathVector m = MathVector(input.getDim(), tmp);
    delete[] tmp;
    return m;
    // no copy constructior <- compiler copy elision
}
MathVector MathVector::operator/(int input) const
{
    int *tmp = new int[_dim];
    for (int i = 0; i < _dim; i++)
    {
        tmp[i] = _arr[i] / input;
    }
    MathVector m = MathVector(_dim, tmp);
    delete[] tmp;
    return m;
}

bool MathVector::operator>(const MathVector &input)
{
    return this->length() > input.length();
}
bool MathVector::operator<(const MathVector &input)
{
    return this->length() < input.length();
}
std::string MathVector::toString()
{
    std::string tmp = "Dim: ";
    tmp += std::to_string(_dim);
    tmp += ", location is [";
    for (int i = 0; i < _dim; i++)
    {
        tmp += std::to_string(_arr[i]);
        if (i != _dim - 1)
            tmp += ",";
    }
    tmp += "]";
    return tmp;
}
// getter
int MathVector::getDim() const
{
    return _dim;
}
double MathVector::getIndex(int i) const
{
    return _arr[i];
}
double MathVector::length() const
{
    double sum = 0;
    for (int i = 0; i < _dim; i++)
    {
        sum += pow(_arr[i], 2);
    }
    return sqrt(sum);
}
// double dot(MathVector v1){}
void MathVector::multiply(double a)
{
    for (int i = 0; i < _dim; i++)
    {
        _arr[i] *= a;
    }
}
