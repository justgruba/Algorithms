/* Heap Sort - sortowanie przez kopcowanie
Działanie algorytmu:
1. ułożenie danych tablicowaych w kopiec
2. Usunięcie wierzchłoka z kopca ( jest to najwikszy element) poprzez zamianę go z ostatnim liściem drzewa
3. Przywrócić własnosć kopca
4. Ponowanie usunąc wierzchołek
 Algorytm jest złożoności O(N logN)
*/
#include <iostream>
#include "Heap.h"
void display(int* arr, int arrSize){
    std::cout << "Tablica wyjściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
int main() {
    Heap heap;
    //Inicjalizacja tablicy wejściowej
    int arr[] = {15, 34, 25, 45, 23, 56, 85, 34, 23, 11, 9, 5, 78};

    int arrSize = sizeof(arr)/sizeof(*arr);

    std::cout << "Tablica wejściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    heap.HeapSort(arr, arrSize);
    display(arr, arrSize);
    return 0;
}

