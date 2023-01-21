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
    Shape *s; // 不能只向shape的物件(未實體化)，可以指向任何繼承shape的物件
    // Shape s ;-> not working ,becase class contain virtual func
    // Shape *s=new Shape(); not working
    void SetUp() override; //Test 裡的class 所擁有的
    void TearDown() override; //Test 裡的class 所擁有的

};
void TriangleTest::SetUp()  // 自己定義 SetUp
{
    double arr1[2]={0,0};
    double arr2[2]={3,0};
    double arr3[2]={0,4};
    v1=MathVector(2,arr1);
    v2=MathVector(2,arr2);
    v3=MathVector(2,arr3);

    t=Triangle(MathVector(2,arr1),MathVector(2,arr2),MathVector(2,arr3));
    s=&t;
    s = new Triangle(v1,v2,v3);
    std::vector<Shape*> vs;
    vs.push_back(new Triangle(v1,v2,v3));
    // vs.push_back(new Circle());
}
void TriangleTest::TearDown()  // 自己定義 TearDown
{

}
// TEST_F = test fixture
TEST_F(TriangleTest,Perimeter){
    ASSERT_NEAR(t.perimeter(),12,0.1);
    ASSERT_NEAR(s->perimeter(),12,0.1);
}

TEST_F(TriangleTest,Area){
    ASSERT_NEAR(t.area(),6,0.1);
    ASSERT_NEAR(s->area(),12,0.1);
}