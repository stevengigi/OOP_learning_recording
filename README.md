Welcome to the course website of OOP 2022 fall. The source code we wrote in the class will be available here. You can check history tab on the top of this page to see the content of each week. Notably, the teaching materials and methods are credited to Prof. Yu Chin Cheng at CSIE, NTUT. For any inquires, please email shchen@ntut.edu.tw with title [物件導向程式設計]_姓名_學號_班級. Formal format is required in the email.

**Link to Homework: http://140.124.183.78/gitlab/109000000/oop2022f_hw**

### Week 18 01/09 & 01/13 - No Class. Let's you guys prepare for other finals.

### Week 17 01/02 National Hoilday & 01/06 Computer-based Final

- You can expact to have your final grade by 1/11
- Email/Message/talk to me during 1/11 and 1/13
- No Changes possible after sumbitting the grade to school (DEFINITELY　NO)

### Week 16 12/26 Hand-written Final & 12/30 - No Class

- Please reserve time to prepare computer-based final
- Do homework HW08 as practicing the computer-based final

### Week 15 12/23 - Review & Files

- [Move semantics](https://hackingcpp.com/cpp/lang/move_semantics.html)
- Read from Files
  - Fully utilized the << and >>
  - Please send time on reviewing source code on 12/30

### Week 15 12/19 - Stream::string

- Tired of using cout for debugging? Log is the way out.
- toString() as a virtual member function of Shape, derived classes, and MathVector
  - std::stringstream ss;
  - streams, insertion operator <<, extraction operator >>
  - overloading stream extraction operator std::operator <<
  - overloaded operator << works for stringstream
  - When you use these as stream operators (rather than binary shift) the first parameter is a stream. Since you do not have access to the stream object (its not yours to modify) these can not be member operators they have to be external to the class. Thus they must either be friends of the class or have access to a public method that will do the streaming for you.

- Following homeworks
  - hw06 due on 12/22
  - hw07 due on 12/29
  - hw08 due on 01/05

### Week 14 12/16 - Class template & Function template

- Check the code in class
- Why we are having issue when seperating class template into .h and .cpp? [Link](https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor)

### Week 14 12/12 - Factory Design Pattern

- Three methods
  - Static member function
  - friend class
  - friend static function

### Week 13 12/09 - Virtual destructor & Memory Leak

__Constructor and destructors in inheritance and polymorphism and their relation to memory leak__

- A main design use of OO is polymorphism
- but polymorphism is very often enabled through use of pointer
  - base class pointer pointing to a derived class instance
  - calling virtual function through the base class pointer
- the use of pointer to enable polymorphism has potential memory leak
  - for example, class App _owns_ several Shapes
  - owning means when App terminates, all shapes are destroyed
  - App sort the the Shapes, e.g., by area
  - In implementation, we could use
```
std::vector<Shape *> shapes;
```
  - So when App terminates, we have to make sure that all shapes are destroyed
  - this involves calling the right destructors through deleting the pointers in the vector

- before that, let's see how constructor behaves under inheritance
  - In constructing a Square, a Shape is first constructed
    - default constructor of Shape is called if not specified
    - specify the constructor to be used with _constructor member initializer list_
  - (Testing idea) observing the sequence of constructor call through static data members and managing it with static member function
    - [static members](https://www.geeksforgeeks.org/static-keyword-cpp/): a static member of a class is a unique member
      - initialized outside of the class;
      - accessed through class scope operator; or through an instance of the class ( shared by all instances of the class);
      - is inherited by subclass through inheritance

- On to destructor
  - given that Square inherits Shape, when Square object's lifetime ends, ~Square is called and then ~Shape is called
  - same happens when deleting a Square pointer
  - BUT NOT SO when deleting through Shape pointer unless the destructor of Shape is virtual

- on to App
  - vector of pointers to Shape seems to be the only choice because we need polymorphism (sort)
    - with lambda (anonymous function)
  - must have ~App();
  - without virtual destructor in Shape, ~App() will only delete the Shape part, potentially leaking memory.

### Week 13 12/05 - Constant member

-Constant member functions 
  - Those functions that are denied permission to change the values of the data members of their class.
  - Denoted with the keyword const after a function declaration, makes it a compiler error for this class function to change a member variable of the class.

<!---
- Friend
  - Allow functions or other class to access internal elemnets

   - [function template](http://www.cplusplus.com/doc/oldtutorial/templates/)
  - Sorting vertices with a Compare object
  - overloading function call operator in a Compare objects
-->

### Week 12 12/02 - Sick Leave of Teacher :( Sorry for inconvenience.

### Week 12 11/28 - Take care of out-of-order vertices 

- std::sort
  - Dafault operator of std::sort is <
  - Passing compare function as a paramaters to std::sort

- When your constructor become large and deals with something trivials,
  - Simple factory
  - Static function

### Week 11 11/21 - Hand out Handwritten Midtern & 11/25 - Constructor in drvied class & Polymorphism

- Different ways of inheritance: public & private & protected
  - [Link](https://openhome.cc/Gossip/CppGossip/protectedPrivateInheritance.html)
- Constructor initializer list
  - To call base class constructor
  - To initialize local private variable
  - [Link](https://kwcheng0119.pixnet.net/blog/post/43384290)

- Sorting triangles, circles and polygons
  - Elements in an vector (or array) must be of the same type. What type should we put in for ??? Triangle? Polygon? Or what?
  - "A Triangle is a Shape" and "a Polygon is a Shape". So:
    - Create a Shape class with operations to compute area and perimeter
    - derive (inherit) Triangle from Shape
    - Shape is a base (parent) class; Triangle is a derive class
    - repeat for Polygon
  - but when we get an element out, it must have the right operations:
Triangle uses Triangle::area() and Polygon uses Polygon::area()
    - do this by declare Shape::area() to be virtual
    - in Triangle::area(), put in keyword override
  - To have Triangle and Polygon behaves as a Shape inside the random access container, one must use either a pointer or a reference to Shape
- **Polymorphism**: the capability of std::sort to treat Triangle and Polygon as Shape objects and still able to call the correct area and perimeter function requires three things:
  - Base class Shape with virtual (or pure virtual) are and perimeter;
  - derive Triangle and Polygon publicly from Shape and override area and perimeter; and
  - Triangle objects amd Polygon objects are accessed through pointer to Shape or reference to Shape

### Week 10 11/14 - Explain Computer-based Midterm & 11/18 - Inheritance & virtual function 

Suggesting reading : CH 15
- Base class v.s. Drvied class
- Virtual function
  - Member function definition starting with `virtual` and ending with `const = 0`
  - To tell the compiler that this is a **pure virtual function**
  - Class that contains virtual function are **abstract class**

### Week 9 11/7 & 11/11 - Midterm

### Week 8 11/04 - Vector containers & Review before Midterm

- Default constructor will 'not' be generated automatically
    - When there is another constructor with some passed parameters
    - When a fix-sized array of the defined object is decleared
    - When a variable-sized array is decleared
    - When template class is been used

- Vector
    - subcategory of Standard Template Library
    - sequence containers representing arrays that can change in size.
    - [Link1](https://shengyu7697.github.io/std-vector/)、[Link2](https://cplusplus.com/reference/vector/vector/?kw=vector)

### Week 8 10/31 - NO CLASS (School Anniversary Celebration)

### Week 7 10/28 - The left right issue

- Left value v.s Right value
    - lvalue have memory space and can be reference to
    - rvalue do not have memory space 
    - lvalue reference v.s rvalue reference
    - & v.s &&
    - Forcing casting temporal rvalue to lvalue through "const" before "&" in function paramaters
    - return lvalue reference to have the effect of both getter and setter

- Move semantics
    - std::move -> Returns an rvalue reference to arg [Link](https://cplusplus.com/reference/utility/move/?kw=move)
    - After move, original value should be left empty
    - Avoid copying from rvalue

### Week 7 10/24 - NO CLASS (Official Leave of Teacher)

### Week 6 10/21 - Google Text Fixture & Seperating definition from declaration

- Four questions to ask when writing a member function
  - what is the name?
  - what are the arguments?
  - what is the return type?
  - is it a constant?
- Tiring of douplicated codes when writing test cases?
  - [test fixture](https://github.com/google/googletest/blob/master/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests-same-data-multiple-tests)
- **You shuold see error when calling a non-constant member function from a constant object**

### Week 6 10/17 - default / delete / Inline call to other constructor

- Please lookup the reserved word: default/delete in C++
- Inline function call can be very useful
- Constructor initializer list
  - To call base class constructor
  - To initialize local private variable
  - [Link](https://kwcheng0119.pixnet.net/blog/post/43384290)
  
### Week 5 10/14 - Addressof operator v.s. Reference

Suggesting reading : CH 10

- What is the difference of following operators?


      double *p, v; 
      p = &v; // & Addressof operator
      *p = 12; // * dereferencing operator
      
      int r; 
      int &xp = r; // reference


- The concept of reference
  - Avoid copy constructor when passing by reference
  - Must be initialized when declaring

- When you find a bug:
    - write a test that fails due to the bug
    - fix the bug
    - compile and run the test
    - repeat until tests pass

- Refactoring: we extracted the private function MathVector::initialize(double * a, int dim) which is used in two constructors and copy assignment. The act is called "refactoring" (Extract Function in this case) that meets three conditions:
    - not changing external behavior of the changed methods, the constructors and copy assignments
    - changing the internal structure: in this case, removed duplicated code in the member functions into a private member function (the initialize)
    - there unit tests that checked on the affected code. The tests must be passing before/after the change
    - reference: Extract Method

### Week 5 10/10 - NO CLASS (National Holiday)

### Week 4 10/07 - Copy Assignment

- copy assignment
  - right associative w = u = v; => w = (u = v);
  - return by reference
  - the this pointer
  - automatically generated if not defined shallow copy not deep copy

Example

    class MyClass obj1, obj2;
    class MyClass obj3(obj1);     //Calls Copy Constructor
    class MyClass obj4 = obj1;    //Calls Copy Constructor
    obj1 = obj2;                  //Calls Copy Assignment Operator

### Week 4 10/03 - Indepth on copy constructor 

Suggesting reading : Passed by reference (&)

- Copy constructor - may be called in the following cases: 
  1. When an object of the class is returned by value. 
  2. When an object of the class is passed (to a function) by value as an argument. 
  3. When an object is constructed based on another object of the same class. 
  4. When the compiler generates a temporary object.

### Week 3 9/30 - Handling exception

Suggesting reading : CH 7.1 & CH 8.1

**Problem III** Let _v_ be a n-dimensional vector and _a_ be a real number. Write a program to calculate its scalar multiplication _a_ _v_.

**Problem IV** Let _u_, _v_ be n-dimensional vectors. Write a program to calculate add u to v to obtain _u_ + _v_

**Problem V** Let _u_, _v_ be n-dimensional vectors and _a_, _b_ be real numbers. Write a program to calculate _a_ _u_ + _b_ _v_

- Handle exception
- Pointer
  - *a, a[], &a
- runtime model of program
  - data, text, stack, heap
- memory allocation/deallocation from heap
  - new operator: allocating space from heap
  - delete operator: de-allocating space from heap
  - memory leak: allocated space NOT de-allocated when it's done used

Quick notice : Next year, we will have huge reudction (down to 10 peoples) in accepting people on joining this course. Please pass this year!

### Week 3 9/26 - Dedining a member function for class

Suggesting reading : CH 6

**Problem II** Deriving the inner product of two vector.

      [1, 0] · [1, 1] = 1,
      [1, 1, 0] · [0, 1, 1] = 1, and
      [1, 0] · [1, 1, 0] => undefined.

**The plan** [Inner product, round 1](http://htsicpp.blogspot.com/2014/08/inner-product-round-1.html)

### Week 2 9/23 - Knowning class & constructor with the MathVector example

Reference
- Text book
- [cplusplus.com](https://www.cplusplus.com/)
- [googletest](https://github.com/google/googletest/blob/master/docs/primer.md)

We will solve a few problems together through the practices of "How To Solve It". 

**Problem solving**

- understanding the problem
- devising a plan
- carrying out the plan
- looking back

**Problem I** Let v a n-dimensional vector. Write a program to calculate its length | v |.

If you're not familiar with vector, read [here](https://en.wikipedia.org/wiki/Vector_space).

### Week 2 9/19 - Get Started with the HelloWolrd Examples to be Familiar with Unit Test

Suggesting reading : Slieds in MS teams & CH 2

Homework : Follow the slides to setup environment (09/23 24:00) & Sumbit code to gitlab (09/30 24:00)

### Week 1 - Introduction & Environment 

Setup Suggesting reading : following links & CH 1

In this semester, 3 things will be given to assist you in your future career.
- [How To Solve It](http://htsicpp.blogspot.com/2014/08/introducing-how-to-solve-it-cpp.html) (Proposed by George Pólya)
- C++ (version 11)
- Engineering practices (unit testing, version control, make, incremental development, test driven development, pair programming, and mob programming, [using Linux cmds](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview))
