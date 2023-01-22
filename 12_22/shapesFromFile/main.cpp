#include <iostream>
#include "shape.h"
#include "triangle.h"
#include "util.h"

// ./bin/ut_all
// ./bin/main source.txt

int main(int argc, char** argv){
    if(argc != 2){
        std::cout<<"Too few arguments.\n";
        return EXIT_FAILURE;
    }
    std::vector <Shape*> s = shapesFromFile(argv[1]);
    std::cout<<s[0]->getName()<<std::endl;

    return EXIT_SUCCESS;
}
