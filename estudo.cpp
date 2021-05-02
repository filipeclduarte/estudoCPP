//
// Created by filipe on 30/04/2021.
//

#include <vector>
#include <iostream>
#include <numeric>
#include <complex>

template <typename T>
T media(const std::vector<T>& x){
    return std::accumulate(x.begin(), x.end(), 0) / x.size();
}
template <typename T>
T variancia(const std::vector<T>& x){
    T m = media(x);
    T sqM = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
    return sqM / x.size() - m * m;
}
template <typename T>
T desvPad(const std::vector<T>& x){
    return std::sqrt(variancia(x));
}

int main(){

    std::vector<int> vec(10);

    for (auto & it : vec){
        std::cout << it << " ";
    }

    std::cout << "Média: ";
    std::cout << media(vec) << std::endl;
    std::cout << "Variância: ";
    std::cout << variancia(vec) << std::endl;
    std::cout << "Desvio pad: ";
    std::cout << desvPad(vec) << std::endl;



}