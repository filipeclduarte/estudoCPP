//
// Created by filipe on 03/05/2021.
//

#include <iostream>
#include <memory>

void populateRandomArray(int *arr, int size){
    for (int i = 0; i < size; i++){
        arr[i] = (std::rand() % 100 ) + 1;
    }
}

void populateRandomMat(int *arr, int rows, int cols){
//    int size = rows * cols;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            arr[i * cols + j] = (std::rand() % 100 ) + 1;
        }
    }
}

int* sum(int *x, int *y, int size){
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = x[i] + y[i];
    }
    return arr;
}

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
    std::unique_ptr<int[]> myMat2(new int[rows * cols]);


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

    // utilizando funcao populateRandomArray
    // criando array dinamica
    int sizeRandom;
    std::cout << "Qual o tamanho da Array aleatória? ";
    std::cin >> sizeRandom;
    int *myRandomArray = new int[sizeRandom];
    populateRandomArray(myRandomArray, sizeRandom);

    // mostrar randomarray
    for(int i = 0; i < sizeRandom; i++)
    {
        std::cout << myRandomArray[i] << "  ";
//        std::cout << *(myRandomArray + i) << "  ";
    }
    // deletar
    delete [] myRandomArray;
    myRandomArray = NULL;

    // randomMat
    int rowsM;
    int colsM;
    std::cout << "Qual o tamanho da Matriz aleatória? ";
    std::cout << "Linhas: ";
    std::cin >> rowsM;
    std::cout << "Colunas: ";
    std::cin >> colsM;

    int *myRandomMat = new int[rowsM * colsM];
    populateRandomMat(myRandomMat, rowsM, colsM);

    // mostrar randomMat
    for(int i = 0; i < rowsM; i++)
    {
        for (int j = 0; j < colsM; j++)
        {
            std::cout << myRandomMat[i * colsM + j] << "  ";
//            std::cout << *(myRandomArray + i) << "  ";
        }
    }
    // deletar
    delete [] myRandomMat;
    myRandomMat = NULL;


    // testando soma de arrays
    std::cout << "\nIniciando soma de arrays" << std::endl;
    int *x = new int[size];
    populateRandomArray(x, size);
    int *y = new int[size];
    populateRandomArray(y, size);
    int *z = sum(x, y, size);
    // mostrar x, y e z
    for(int i = 0; i < size; i++)
    {
        std::cout << "x[" << i << "] = " << x[i] << " + " << "y[" << i << "] = " << y[i] << " = " << z[i] << std::endl;
    }

    delete [] x;
    x = NULL;
    delete [] y;
    y = NULL;
    delete [] z;
    z = NULL;

    return 0;
}
