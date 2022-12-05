####  OOP 9/19

- learn how to use gtest and makefile
    - understand the makefile command ex:makefile
        - step_1 : command : makefile
        - step_2 : if succcess , then  command : ./ut_all
    - how to use gtest
        - function : TEST(HELLOWORLD,Print)
            - HELLOWORLD is the test function name(Equal to the test file name is better)
            - Print is the test function in the HelloWorld.h
        - ASSERT_EQ(compare,output);
            - ASSERT_EQ is compare the input if it is same return OK ,otherwise False
            - compare is the true answer(you wish)
            - output is the function output which you write