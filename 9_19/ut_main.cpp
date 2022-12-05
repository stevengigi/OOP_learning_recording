#include<gtest/gtest.h>
#include"HelloWorld.h"

TEST(HELLOWORLD,Print){
    std::string compare="Hello World";
    std::string output=print();

    ASSERT_EQ(compare,output);
}

int main(int argc ,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}