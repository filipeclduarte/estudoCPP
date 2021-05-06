#include <array>
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <numeric>

template<typename T, size_t N>
void randomArray(std::array<T, N> &arr, unsigned seed){
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    for (double & it : arr){
        it = distribution(generator);
    }
}

template<typename T, size_t N>
std::array<T, N> operator+(const std::array<T, N>& x, const std::array<T, N>& y){
    // assert(x.size() == y.size());
    std::array<T, N> res;
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] + y[i];
    }
    return res;
}

template<typename T, size_t N>
std::array<T, N> operator-(const std::array<T, N>& x, const std::array<T, N>& y){
    // assert(x.size() == y.size());
    std::array<T, N> res;
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] - y[i];
    }
    return res;
}

template<typename T, size_t N>
std::array<T, N> operator*(const std::array<T, N>& x, const std::array<T, N>& y){
    // assert(x.size() == y.size());
    std::array<T, N> res;
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] * y[i];
    }
    return res;
}

template<typename T, size_t N>
std::array<T, N> operator/(const std::array<T, N>& x, const std::array<T, N>& y){
    // assert(x.size() == y.size());
    std::array<T, N> res;
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] + y[i];
    }
    return res;
}

template<typename T, size_t N>
std::array<T, N> pow(const std::array<T, N>& x, const double& y){
    std::array<T, N> res;
    for (int i = 0; i < x.size(); i++){
        res[i] = std::pow(x[i], y);
    }
    return res;
}

template<typename T, size_t N>
std::array<T, N> exp(const std::array<T, N>& x){
    std::array<T, N> res;
    for (int i = 0; i < x.size(); i++){
        res[i] = std::exp(x[i]);
    }
    return res;
}

template<typename T, size_t N>
T sum(const std::array<T, N> &x){
    return std::accumulate(x.begin(), x.end(), 0.0);
}

template<typename T, size_t N>
T prod(const std::array<T, N> &x){
    return std::accumulate(x.begin(), x.end(), 1.0, std::multiplies<T>());
}

// estatisticas
template<typename T, size_t N>
T mean(const std::array<T, N> &x){
    return std::accumulate(x.begin(), x.end(), 0.0) / x.size();
}

template<typename T, size_t N>
T variance(const std::array<T, N> &x){
    T m = mean(x);
    T sqSum = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
    return sqSum / x.size() - m * m;
}

template<typename T, size_t N>
T stD(const std::array<T, N> &x){
    return std::sqrt(variance(x));
}

template<typename T, size_t N>
std::vector<std::vector<T> > seriesToSupervised(const std::array<T, N> &x, int nInputs){
    int nRows = x.size() - nInputs + 1;
    std::vector<std::vector<T> > res(nRows, std::vector<T>(nInputs, 0));
    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < nInputs; j++){
            res[i][j] = x[i + j];
        }
    }
    return res;

}


int main(){

    // gerando array aleatoria
    std::array<double, 100> arr;
    randomArray(arr, 100);
    
    // mostrar valores
    std::cout << "[ ";
    for (const double &it : arr){
        std::cout << it << " ";
    }
    std::cout << "]" << std::endl;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::array<double, 100> X;
    std::array<double, 100> Y;
    std::array<double, 100> Z;

    randomArray(X, seed + rand());
    randomArray(Y, seed + rand());
    Z = X + Y;

    std::cout << "PLUS" << std::endl;
    for (int i = 0; i < Z.size(); i++){
        std::cout << "Z[" << i << "] = " << Z[i] << std::endl;
    }

    std::cout << "MINUS" << std::endl;
    Z = X - Y;
    for (int i = 0; i < Z.size(); i++){
        std::cout << "Z[" << i << "] = " << Z[i] << std::endl;
    }

    std::cout << "PROD" << std::endl;
    Z = X * Y;
    for (int i = 0; i < Z.size(); i++){
        std::cout << "Z[" << i << "] = " << Z[i] << std::endl;
    }

    std::cout << "DIV" << std::endl;
    Z = X / Y;
    for (int i = 0; i < Z.size(); i++){
        std::cout << "Z[" << i << "] = " << Z[i] << std::endl;
    }

    std::cout << "POW" << std::endl;
    std::array<double, 100> X2 = pow(X, 2.0);
    for (int i = 0; i < X2.size(); i++){
        std::cout << "X2[" << i << "] = " << X2[i] << std::endl;
    }

    double mediaX2 = mean(X2);
    double varX2 = variance(X2);
    double stdX2 = stD(X2);
    
    std::cout << "Média de X2: " << mediaX2 << std::endl;
    std::cout << "Variância de X2: " << varX2 << std::endl;
    std::cout << "Desvio padrão de X2: " << stdX2 << std::endl;
    int inputs = 10;
    int nRows = X2.size() - inputs + 1;
    std::vector<std::vector<double> > X2series = seriesToSupervised(X2, inputs);

    for (int i = 0; i < nRows; i++){
        for (int j = 0; j < inputs; j++){
            // Prints ' ' if j != n-1 else prints '\n'          
            std::cout << X2series[i][j] << " \n"[j == inputs-1];

        }
    }
    
    double produto = prod(X2);
    std::cout << "Produto de X2: " << produto << std::endl;
    
    return 0;
}