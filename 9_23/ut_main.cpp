#include<gtest/gtest.h>
#include "ut_helloworld.h"
#include "ut_length.h"



int main(int argc ,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}