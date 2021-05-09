#include <iostream>
#include "myVec.h"

// comando para compilar: g++ myVec.cpp testemyVec.cpp -o testVec
int main(){

    // criando myVector
    int size = 10;
    myVector vec(size);

    // preencher os valores 
    for (int i = 0; i < vec.size(); i++){
        vec[i] = i;
    }
    // mostrar valores
    for (int i = 0; i < vec.size(); i++){
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    // mean
    std::cout << "Mean: " << vec.mean() << std::endl;
    
    // variance
    std::cout << "Variance: " << vec.var() << std::endl;

    // standard deviation
    std::cout << "Standard deviation: " << vec.stDev() << std::endl;

    // criar outro vector e somar ao vec
    myVector vec2(size);
    // preencher os valores 
    for (int i = 0; i < vec2.size(); i++){
        vec2[i] = i * 2.0;
    }

    myVector vec3 = vec + vec2;
    // mostrar valores
    // mostrar valores
    for (int i = 0; i < vec3.size(); i++){
        std::cout << "vec3[" << i << "] = " << vec3[i] << std::endl;
    }

    return 0;
}


