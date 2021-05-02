#include <array>
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <numeric>

// gerando vector aleatorio
std::vector<double> randomVector(int n, unsigned seed){
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    std::vector<double> arr(n);
    for (double & it : arr){
        it = distribution(generator);
    }
    return arr;
}

std::vector<double> randomNormalVector(int n, unsigned seed){
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution(0.0,1.0);

    std::vector<double> arr(n);
    for (double & it : arr){
        it = distribution(generator);
    }
    return arr;
}

// operacoes vetoriais 
std::vector<double> operator+(const std::vector<double>& x, const std::vector<double>& y){
    assert(x.size() == y.size());
    std::vector<double> res(x.size());
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] + y[i];
    }
    return res;
}

std::vector<double> operator-(const std::vector<double>& x, const std::vector<double>& y){
    assert(x.size() == y.size());
    std::vector<double> res(x.size());
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] - y[i];
    }
    return res;
}

std::vector<double> operator*(const std::vector<double>& x, const std::vector<double>& y){
    assert(x.size() == y.size());
    std::vector<double> res(x.size());
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] * y[i];
    }
    return res;
}

std::vector<double> operator/(const std::vector<double>& x, const std::vector<double>& y){
    assert(x.size() == y.size());
    std::vector<double> res(x.size());
    for (int i = 0; i < x.size(); i++){
        res[i] = x[i] / y[i];
    }
    return res;
}

std::vector<double> pow(const std::vector<double>& x, const double& y){
    std::vector<double> res(x.size());
    for (int i = 0; i < x.size(); i++){
        res[i] = std::pow(x[i], y);
    }
    return res;
}

// estatisticas
double mean(const std::vector<double> &x){
    return std::accumulate(x.begin(), x.end(), 0.0) / x.size();
}

double variance(const std::vector<double> &x){
    double m = mean(x);
    double sqSum = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
    return sqSum / x.size() - m * m;
}

double stD(const std::vector<double> &x){
    return std::sqrt(variance(x));
}

std::vector<std::vector<double> > randomMatrix(int n, int m, unsigned seed){
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    std::vector<std::vector<double> > res(n, std::vector<double>(m, 0.0));
    for (std::vector<double> & it : res){
        for (double & el : it){
            el = distribution(generator);
        }
    }
    return res;
}

std::vector<std::vector<double> > randomNormalMatrix(int n, int m, unsigned seed){
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution(0.0,1.0);

    std::vector<std::vector<double> > res(n, std::vector<double>(m, 0.0));
    for (std::vector<double> & it : res){
        for (double & el : it){
            el = distribution(generator);
        }
    }
    return res;
}

// matrix sum
template <class T>
std::vector <std::vector<T> > operator+(const std::vector <std::vector<T> > &x, const std::vector <std::vector<T> > &y){
    assert(x.size() == y.size() && x[0].size() == y[0].size());
    
    const int n = x.size();
    const int m = x[0].size();

    std::vector <std::vector<T> > res(n, std::vector<T>(m, 0));
    for (auto i = 0; i < n; i++){
        for (auto j = 0; j < m; j++){
            res[i][j] = x[i][j] + y[i][j];
        }
    }
    return res;
}

template <class T>
std::vector <std::vector<T> > operator-(const std::vector <std::vector<T> > &x, const std::vector <std::vector<T> > &y){
    assert(x.size() == y.size() && x[0].size() == y[0].size());
    
    const int n = x.size();
    const int m = x[0].size();

    std::vector <std::vector<T> > res(n, std::vector<T>(m, 0));
    for (auto i = 0; i < n; i++){
        for (auto j = 0; j < m; j++){
            res[i][j] = x[i][j] - y[i][j]; 
        }
    }
    return res;
}

template <class T>
std::vector <std::vector<T> > operator*(const std::vector <std::vector<T> > &x, const std::vector <std::vector<T> > &y){
    assert(x.size() == y.size() && x[0].size() == y[0].size());
    
    const int n = x.size();
    const int m = x[0].size();

    std::vector <std::vector<T> > res(n, std::vector<T>(m, 0));
    for (auto i = 0; i < n; i++){
        for (auto j = 0; j < m; j++){
            res[i][j] = x[i][j] * y[i][j];
        }
    }
    return res;
} 

template <class T>
std::vector <std::vector<T> > operator/(const std::vector <std::vector<T> > &x, const std::vector <std::vector<T> > &y){
    assert(x.size() == y.size() && x[0].size() == y[0].size());
    
    const int n = x.size();
    const int m = x[0].size();

    std::vector <std::vector<T> > res(n, std::vector<T>(m, 0));
    for (auto i = 0; i < n; i++){
        for (auto j = 0; j < m; j++){
            res[i][j] = x[i][j] / y[i][j];
        }
    }
    return res;
}

// matrix multiplication
template <class T>
std::vector <std::vector<T> > matmul(const std::vector <std::vector<T> > &x, const std::vector <std::vector<T> > &y)
{
    const int n = x.size();     // x rows
    const int m = x[0].size();  // y cols
    const int p = y[0].size();  // y cols

    std::vector <std::vector<T> > res(n, std::vector<T>(p, 0));
    for (auto j = 0; j < p; ++j)
    {
        for (auto k = 0; k < m; ++k)
        {
            for (auto i = 0; i < n; ++i)
            {
                res[i][j] += x[i][k] * y[k][j];
            }
        }
    }
    return res;
}


double mean(const std::vector<std::vector<double> > &x){
    double s = 0.0;
    int n = x.size();
    int m = x[0].size();

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            s += x[i][j];
        }
    }
    return s / (n + m);
}


int main(){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    int a;
    std::vector<std::vector<double> > X;
    std::vector<std::vector<double> > Y;
    std::vector<std::vector<double> > Z;
    double m;

    for (int i = 0; i < 30; i++){
        a = 0;
        for (int j = 0; j < 100; j++){
            X = randomNormalMatrix(100, 10, seed * rand() % 100);
            Y = randomNormalMatrix(10, 100, seed * rand() % 100);
            Z = matmul(X, Y);
            m = mean(Z);
            for (int k = 0; k < Z.size(); k++){
                if (Z[k][0] < m){
                    a += 1;
                }
            }
        }
        std::cout << "a: " << a << std::endl; 
    }

    // std::vector<double> X = randomNormalVector(100, seed);
    // std::vector<double> Y = randomVector(100, seed + 100);
    // // std::vector<double> Z = X + Y;
    // std::vector<double> G = X - Y;
    // std::vector<double> H = X * Y;
    // std::vector<double> J = X / Y;
    // std::vector<double> F = pow(X, 2.0);

    //imprimir
    // std::cout << "X: ";
    // for (auto & it : X) std::cout << it << " ";
    // std::cout << "\nY: ";
    // for (auto & it : Y) std::cout << it << " ";
    // std::cout << "\n X + Y: ";
    // for (auto & it : Z) std::cout << it << " ";
    // std::cout << "\n X - Y: ";
    // for (auto & it : G) std::cout << it << " ";
    // std::cout << "\n X * Y: ";
    // for (auto & it : H) std::cout << it << " ";
    // std::cout << "\n X / Y: ";
    // for (auto & it : J) std::cout << it << " ";
    // std::cout << "\n pow(X, 2.0): ";
    // for (auto & it : F) std::cout << it << " ";
    
    // std::cout << "\nMédia de X: " << mean(X) << std::endl; 
    // std::cout << "Variância de X: " << variance(X) << std::endl;
    // std::cout << "Desvio pad. de X: " << stD(X) << std::endl;
    // std::cout << "FIM!" << std::endl;

    return 0;
}