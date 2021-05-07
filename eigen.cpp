#include <iostream>
#include <eigen3/Eigen/Dense>


int main(){

    Eigen::MatrixXf X;
    Eigen::MatrixXf Y;
    Eigen::MatrixXf Z;

    int a;
    double m;
    for (int i = 0; i < 30; i++){
        a = 0;
        for (int j = 0; j < 100; j++){
            X = Eigen::MatrixXf::Random(100, 10);
            Y = Eigen::MatrixXf::Random(10, 100);
            Z = X * Y; // matrix multiplication
            m = Z.mean();
            for (int k = 0; k < 100; k++){
                if (Z(k, 0) < m){
                    a += 1;
                }
            }
        }
        std::cout << "a: " << a << std::endl;
    }    

    std::cout << "Element-wise multiplication" << std::endl;
    // element-wise multiplication
    Eigen::MatrixXf Xm;
    Eigen::MatrixXf Ym;
    Eigen::MatrixXf Zm;
    for (int i = 0; i < 30; i++){
        a = 0;
        for (int j = 0; j < 100; j++){
            X = Eigen::MatrixXf::Random(100, 10);
            Y = Eigen::MatrixXf::Random(100, 10);
            Z = X.array() * Y.array(); // element-wise
            m = Z.mean();
            for (int k = 0; k < 100; k++){
                if (Z(k, 0) < m){
                    a += 1;
                }
            }
        }
        std::cout << "a: " << a << std::endl;
    }    





    return 0;
}