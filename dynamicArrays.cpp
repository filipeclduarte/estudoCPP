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
    std::cout << "\nQuantas linhas?" << " ";
    std::cin >> rows;
    std::cout << "Quantas colunas?" << " ";
    std::cin >> cols;

    int *myMat = new int[rows * cols];
    // alocar valores
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            std::cout << "Matriz[" << i << "][" << j << "] = ";
            std::cin>> myMat[i*cols + j];
        }
    }

    // mostrar matriz
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            std::cout << "Matriz[" << i << "][" << j << "] = " << myMat[i*cols + j] << std::endl;
        }
    }

    delete [] myMat;
    myMat = NULL;

    // utilizando smart pointers - quando sai do escopo, deleta-se automaticamente o ponteiro.
    std::cout << "\nUtilizando smart pointer" << std::endl;
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

    std::cout << "Iniciando matriz com smart pointer" << std::endl;
    // usando smart pointer para matriz
    std::unique_ptr<int[]> myMat2(new int[rows * cols]);2


    // preencher os valores
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            std::cout << "Matriz[" << i << "][" << j << "] = ";
            std::cin>> myMat2[i*cols + j];
        }
    }
    // mostrar matriz
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols;j++)
        {
            std::cout << "Matriz[" << i << "][" << j << "] = " << myMat2[i*cols + j] << std::endl;
        }
    }

    

    return 0;
}
