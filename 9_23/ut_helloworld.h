#include<gtest/gtest.h>
#include"HelloWorld.h"

TEST(HELLOWORLD,Print){
    std::string compare="Hello World";
    std::string output=print();

    ASSERT_EQ(compare,output);
}