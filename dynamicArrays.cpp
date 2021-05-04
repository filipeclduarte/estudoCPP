//
// Created by filipe on 03/05/2021.
//

#include <iostream>
#include <memory>

int main(){

    std::cout << "Iniciando o programa!" << std::endl;
    int size;
    std::cout << "Tamanho da array: ";
    std::cin >> size;

    int* myArray = new int[size];
    for(int i = 0; i < size; i++)
    {
        std::cout << "Array[" << i << "] ";
        std::cin >> myArray[i];
    }

    for(int i = 0; i < size; i++)
    {
//        std::cout << myArray[i] << "  ";
         std::cout << *(myArray + i) << "  ";
    }

    // importante deletar o ponteiro
    delete [] myArray;
    myArray = NULL;

    // alocando matriz como array
    int rows, cols;
    std::cout << "Quantas linhas?";
    std::cin >> rows;
    std::cout << "\nQuantas colunas?";
    std::cin >> cols;

    int *myMat = new int[rows * cols];
    // alocar valores
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            std::cout << "Array[" << i << "][" << j << "] = ";
            std::cin>> myMat[i*cols + j];
        }
    }

    // mostrar matriz
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            std::cout << "Array[" << i << "][" << j << "] = " << myMat[i*cols + j] << std::endl;
        }
    }

    delete [] myMat;
    myMat = NULL;

    // utilizando smart pointers - quando sai do escopo, deleta-se o ponteiro.
    std::cout << "Utilizando smart pointer" << std::endl;
    std::unique_ptr<int[]> myArray2(new int[size]);
    // preencher os valores
    for(int i = 0; i < size; i++)
    {
        std::cout << "Array[" << i << "] ";
        std::cin >> myArray2[i];
    }
    // printar
    for(int i = 0; i < size; i++)
    {
        std::cout << myArray2[i] << "  ";
    }




    return 0;
}
