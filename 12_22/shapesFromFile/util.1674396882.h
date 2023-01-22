#pragma once
#include <vector>
#include <fstream>
#include <string>

#include "shape.h"
#include "triangle.h"
#include "math_vector.h"

// ifs should be like this
// based on double *_arr in mathvector;
// tri <- name
// 2 0 0 <- mathvector
// 2 4 0 <- mathvector
// 2 0 4 <- mathvector

// based on vector<double> in mathvector;
// tri <- name
// 0 0 <- mathvector
// 4 0 <- mathvector
// 0 4 <- mathvector

/*
mathvector.h
// based on double *_arr;
friend std::istream &operator>>(std::istream  &input, Mathvector &m) { 
    int tmp_dim;
    inpupt >> tmp_dim;
    if(m._dim != tmp_dim) {
        // deal with new & delete issues
        if(m._dim != 0) {
            delete m._arr;
            //m._arr.clear(); for vector<double>
        }
        m._arr = new double[tmp_dim];
    }
    m._dim = tmp_dim;
    for(i=0 ~ i=m._dim){
        inpupt >> m._arr[i];
    }
    return input;            
}
*/

std::vector<Shape *> shapesFromFile(std::string fileName) {
    std::ifstream ifs(fileName);
    std::string name;
    std::vector<Shape *> shapes;
    // Complicated version
    ifs >> name;
    MathVector _u[3];
    for(int i = 0; i < 3; i++) {
        ifs >> _u[i];
    }
    shapes.push_back(new Triangle(_u[0], _u[1], _u[2], name));
    // Simplified version
    Triangle *triangle = new Triangle();
    ifs >> *triangle;
    shapes.push_back(triangle);

    // Following is wrong because tri disappears after line 33.
    // Triangle tri;
    // ifs >> tri;
    // shapes.push_back(&tri);

    return shapes;
}
