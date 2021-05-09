#include "myVec.h"
#include <cmath>

myVector::myVector(int s) 
    :elem(new double[s]), sz(s) {}

myVector::~myVector(){
    delete[] elem;
}

int myVector::size(){
    return sz;
}

double& myVector::operator[](int i){
    return elem[i];
}

double myVector::mean(){
    double s = 0.0;
    for (int i = 0; i < myVector::size(); i++){
        s += elem[i];
    }
    return s;
}

double myVector::var(){
    double s = 0.0;
    double mu = myVector::mean();
    double var = 0.0;
    for (int i =0; i < myVector::size(); i++){
        var += (elem[i] - mu) * (elem[i] - mu);
    }
    return var/(myVector::size() - 1);
}

double myVector::stDev(){
    double var = myVector::var();
    return std::sqrt(var);
}
