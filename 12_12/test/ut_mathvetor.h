#include<gtest/gtest.h>
#include"../src/MathVector.h"
#include"../src/length.h"

TEST(MATHVECTOR,Dot){
    double arr1[2]={1,2};
    double arr2[2]={3,4};
    int dim=2;
    MathVector v1(dim,arr1);
    MathVector v2(dim,arr2);
    double result = dot(v1,v2);
    ASSERT_NEAR(result,11,0.1);
}
TEST(MATHVECTOR,Multiply){
    double arr1[2]={1,2};
    int dim=2;
    MathVector v1(dim,arr1);
    v1.multiply(3); // return nothing
    ASSERT_NEAR(v1.getIndex(0),3,0.1);
    ASSERT_NEAR(v1.getIndex(1),6,0.1);
}
TEST(MATHVECTOR,Dot_Throw){
    double arr1[2]={1,2};
    double arr2[3]={3,4,5};
    int dim=2;
    MathVector v1(dim,arr1);
    MathVector v2(3,arr2);
    ASSERT_THROW(dot(v1,v2),std::string); // Undefined behavior , using "throw" to test
}
TEST(MATHVECTOR,Assignment){
    double arr1[2]={1,2};
    double arr2[3]={3,4,5};
    double arr3[3]={6,7,8};
    MathVector v1(2,arr1);
    MathVector v2(3,arr2);
    MathVector v3(3,arr3);
    v1=v2;
    ASSERT_EQ(v1.getDim(),3);
    ASSERT_NEAR(v1.getIndex(0),arr2[0],0.1);
    ASSERT_NEAR(v1.getIndex(1),arr2[1],0.1);
    ASSERT_NEAR(v1.getIndex(2),arr2[2],0.1);

    v1=v2=v3;
    ASSERT_EQ(v1.getDim(),3);
    ASSERT_NEAR(v1.getIndex(0),arr3[0],0.1);
    ASSERT_NEAR(v1.getIndex(1),arr3[1],0.1);
    ASSERT_NEAR(v1.getIndex(2),arr3[2],0.1);
    ASSERT_EQ(v2.getDim(),3);
    ASSERT_NEAR(v2.getIndex(0),arr3[0],0.1);
    ASSERT_NEAR(v2.getIndex(1),arr3[1],0.1);
    ASSERT_NEAR(v2.getIndex(2),arr3[2],0.1);
}
TEST(MATHVECTOR,Add){
    double arr1[2]={1,2};
    double arr2[3]={3,4,5};
    double arr3[3]={6,7,8};
    MathVector v1(2,arr1);
    MathVector v2(3,arr2);
    MathVector v3(3,arr3);
    v1=v2+v3; // v1 = rvalue ->if no move assignment ,do copy assignment
    ASSERT_EQ(v1.getDim(),3);
    ASSERT_NEAR(v1.getIndex(0),9,0.1);
    ASSERT_NEAR(v1.getIndex(1),11,0.1);
    ASSERT_NEAR(v1.getIndex(2),13,0.1);
}
TEST(MATHVECTOR,Compare){
    double arr2[3]={3,4,5};
    double arr3[3]={6,7,8};
    MathVector v2(3,arr2);
    MathVector v3(3,arr3);
    ASSERT_TRUE(v2<v3);
    ASSERT_FALSE(v2>v3);
}
TEST(MATHVECTOR,ToString){
    double arr2[3]={3,4,5};
    MathVector v2(3,arr2);
    std::cout << v2.toString()<<std::endl;
}
TEST(MATHVECTOR,Divide){
    double arr2[3]={3,4,5};
    double arr3[3]={6,8,10};
    MathVector v2(3,arr2);
    MathVector v3(3,arr3);
    MathVector v1;
    v1=v2/v3;
    ASSERT_NEAR(v1.getIndex(0),0.5,0.1);
    ASSERT_NEAR(v1.getIndex(1),0.5,0.1);
    ASSERT_NEAR(v1.getIndex(2),0.5,0.1);
}