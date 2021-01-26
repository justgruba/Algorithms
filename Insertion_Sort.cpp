/* Sortowanie przez wstawianie polega na dzieleniu tablicy na podtablice posortowanych i nieposortowanych
 elementów. Wybiera się jeden element odniesienia i iteruje po posortowanej liście na podstawie porównywania
 wartości elementów. W najlepszym przypadku złożoność czasowa tego elgorytmu wynosi O(n)*/
#include <iostream>
#include "Insert.h"

void display(int* arr, int arrSize){
    std::cout << "Tablica wyjściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
int main() {
    Insert insert;
    //Inicjalizacja tablicy wejściowej
    int arr[] = {4, 3, 2, 1};

    int arrSize = sizeof(arr)/sizeof(*arr);

    std::cout << "Tablica wejściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    insert.InsertionSort(arr, arrSize);

    display(arr, arrSize);
    return 0;
}
