/* MergeSort inaczej sortowanie przez scalanie polega na dzieleniu tablicy na dwie mniejsze podtablice,
 a następnie sortowaniu poszczególnych podtablic.
Kod MegreSort potrzebuje dwóch funkcji, aby posortować tablicę:
 1. Merge() - używana jest kiedy wszystkie połówki podtablicy zostały posortowane.
 2. MergeSort() - dzieli tablicę na dwie podtablice. */

/* Kolejne etapy funkcji Merge():
 1. Określenie liczby elementów, które zostaną scalone - totalElements
 2. Zainicjownie tymczasowej tablicy do przetrzymywania scalonych elementów
 3. określenie skrajnych elementów z lewej strony dwóch podtablic
 4. Ostatni indeks scalone tablicy - mergedIndex
 5. Za pomocą pętli calanie podtablic
    5.1 przechowywanie w tymczasowej tablicy elementu, który ma niższą wartość z lewej podtablicy
    5.2 przechowywanie w tymczasowej  tablicy elementu, który ma niższą wartość z prawej podtablicy
 6. Wstawnienie elementów, które nie zostały posortowane
 7. Skopiowanie elementów z tymczasowej podtalicy do tablicy wyjściowej */
#include <iostream>
#include "Merge.h"

void display(int *arr, int arrSize){

    std::cout << "Tablica wyjściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
int main() {
    Merge merge;
    //Inicjalizacja tablicy wejściowej
    int arr[] = {15, 34, 25, 45, 23, 56, 85, 34, 23, 11, 9, 5, 78};

    int arrSize = sizeof(arr)/sizeof(*arr);

    std::cout << "Tablica wejściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    merge.MergeSort(arr, 0, arrSize-1);
    display(arr,arrSize);
    return 0;
}
