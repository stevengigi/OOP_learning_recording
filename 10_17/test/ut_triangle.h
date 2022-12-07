#include<gtest/gtest.h>
#include"../src/Triangle.h"

TEST(TRIANGLE,Area){
    double arr1[2]={0,0};
    double arr2[2]={3,0};
    double arr3[2]={0,4};
    MathVector v1(2,arr1);
    MathVector v2(2,arr2);
    MathVector v3(2,arr3);
    Triangle t(v1,v2,v3);
    ASSERT_NEAR(t.primeter(),12,0.1);
}