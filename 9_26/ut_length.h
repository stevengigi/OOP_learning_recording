#include<gtest/gtest.h>
#include"length.h"


TEST(LENGTH,Two_Dim){
    double arr[2]={3,4};
    int dim=2;
    double output = length(arr,dim);
    ASSERT_EQ(output,5);
}

TEST(LENGTH,Three_Dim){
    double arr[3]={3,4,5};
    int dim=3;
    double output = length(arr,dim);
    ASSERT_NEAR(output,7.07,0.01); // ASSERT_NEAR(compare , output , abs error)
}

TEST(LENGTH,Two_Dim_MathVector){
    double arr[2]={3,4};
    int dim=2;
    // MathVector m; -> default constructor
    MathVector m(dim,arr);
    double output = length(m);
    ASSERT_EQ(output,5);
}

