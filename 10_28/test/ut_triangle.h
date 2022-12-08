#include<gtest/gtest.h>
#include"../src/Triangle.h"
//test fixture
class TriangleTest : public::testing::Test //inheritance(繼承)
{
protected:
    MathVector v1;
    MathVector v2;
    MathVector v3;
    Triangle t;
    void SetUp() override; //Test 裡的class 所擁有的
    void TearDown() override; //Test 裡的class 所擁有的

};
void TriangleTest::SetUp()  // 自己定義 SetUp
{
    double arr1[2]={0,0};
    double arr2[2]={3,0};
    double arr3[2]={0,4};
    // v1=MathVector(2,arr1);
    // v2=MathVector(2,arr2);
    // v3=MathVector(2,arr3);

    t=Triangle(MathVector(2,arr1),MathVector(2,arr2),MathVector(2,arr3));
}
void TriangleTest::TearDown()  // 自己定義 TearDown
{

}
// TEST_F = test fixture
TEST_F(TriangleTest,Perimeter){
    ASSERT_NEAR(t.perimeter(),12,0.1);
}

TEST_F(TriangleTest,Area){
    ASSERT_NEAR(t.area(),6,0.1);
}