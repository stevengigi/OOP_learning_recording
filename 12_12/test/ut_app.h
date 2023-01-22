#include<gtest/gtest.h>
#include"../src/App.h"
#include"../src/MathVector.h"
#include"../src/Circle.h"
#include"../src/Triangle.h"
#include"../src/Polygon.h"
 class AppTest:public ::testing::Test
{
protected:
    double arr[2];
    double arr1[2];
    double arr2[2];
    double arr3[2];
    MathVector mv;
    MathVector mv1;
    MathVector mv2;
    MathVector mv3;
    Circle *c;
    Polygon *p;
    Triangle *t;
    Shape *s;
    PolygonFactory pf;
    void SetUp() override;
    void TearDown() override;
};
void AppTest::SetUp()
{
    arr[0]=0;
    arr[1]=0;
    arr1[0]=4;
    arr1[1]=4;
    arr2[0]=4;
    arr2[1]=0;
    arr3[0]=0;
    arr3[1]=4;
    mv=MathVector(2,arr);
    mv1=MathVector(2,arr1);
    mv2=MathVector(2,arr2);
    mv3=MathVector(2,arr3);
    std::cout << "A-------------------------\n";
    c=new Circle(mv,10);
    std::cout << "A-------------------------\n";
    t=new Triangle(mv,mv1,mv2);
    MathVector arr4[4]={mv,mv1,mv2,mv3};
    // p=new Polygon(arr4,4);
    Polygon temp=CreatPolygon(arr4,4);
    p=&temp;
    p=pf.CreatePolygonPtr(arr,4);
    std::cout << "B-------------------------\n";
    s=new Circle(mv,10,"temp");
    std::cout << "B-------------------------\n";
}
void AppTest::TearDown()
{
    if(c!=nullptr){
        delete c;
    }
    if(t!=nullptr){
        delete c;
    }
    if(p!=nullptr){
        delete c;
    }
    if(s!=nullptr){
        delete s;
    }
}


TEST_F(AppTest,ADDTEST){
    App app;
    app.appAdd(c);
    app.appAdd(t);
    app.appAdd(p);
    app.getIndex(0)->getname();
    // ASSERT_EQ()
    ASSERT_NEAR(app.getIndex(0)->area(),314,1);
    ASSERT_NEAR(app.getIndex(1)->area(),8,1);
    ASSERT_NEAR(app.getIndex(2)->area(),16,1);

}
TEST_F(AppTest,EXCHANGE_TEST){
    App app;
    app.appAdd(c);
    app.appAdd(t);
    app.appAdd(p);
    exchange(app.getIndex(0),app.getIndex(1))
    app.getIndex(0)->getname();
    // ASSERT_EQ()
    ASSERT_NEAR(app.getIndex(0)->area(),314,1);
    ASSERT_NEAR(app.getIndex(1)->area(),8,1);
    ASSERT_NEAR(app.getIndex(2)->area(),16,1);

}