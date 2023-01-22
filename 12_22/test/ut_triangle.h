#include <gtest/gtest.h>
#include "../src/Triangle.h"

// test fixture
class TriangleTest : public ::testing::Test
{
protected:
    MathVector v1;
    MathVector v2;
    MathVector v3;
    Triangle t;
    Shape *s;
    // Shape s; -> not working
    // Shape *s = new Shape(); -> not working
    void SetUp() override;
    void TearDown() override;
    double area;
    double perimeter;
};

void TriangleTest::SetUp()
{
    double arr1[2] = {0, 0};
    double arr2[2] = {3, 0};
    double arr3[2] = {0, 4};
    area = 6;
    perimeter = 12;
    // v1 = MathVector(2, arr1);
    //  v2 = MathVector(2, arr2);
    //   v3 = MathVector(2, arr3);
    //    t = Triangle(v1, v2, v3);

    t = Triangle(MathVector(2, arr1), MathVector(2, arr2), MathVector(2, arr3));
    std::cout << "After triangle" << std::endl;

    // s = &t;
    // s = new Triangle(v1, v2, v3);

    // std::vector<Shape *> vs;
    // vs.push_back(new Triangle(v1, v2, v3));
    // vs.push_back(new Circle());
}

void TriangleTest::TearDown()
{
}

TEST_F(TriangleTest, Perimeter)
{
    ASSERT_NEAR(t.perimeter(), perimeter, 0.01);
    // ASSERT_NEAR(s->perimeter(), perimeter, 0.01);
}

TEST_F(TriangleTest, Area)
{
    ASSERT_NEAR(t.area(), area, 0.01);
    // ASSERT_NEAR(s->area(), area, 0.01);
}