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

void Merge(int arr[], int startInedx, int middleIndex, int endIndex){
    int totalElements = endIndex - startInedx +1;
    int * tempArray = new int[totalElements];
    int leftIndex = startInedx;
    int rightIndex = middleIndex+1;
    int mergedIndex = 0;

    while(leftIndex <= middleIndex && rightIndex <= endIndex){
        if(arr[leftIndex] <= arr[rightIndex]) {
            tempArray[mergedIndex] = arr[leftIndex];
            ++leftIndex;
        }
        else{
            tempArray[mergedIndex] = arr[rightIndex];
            ++rightIndex;
        }
        ++mergedIndex;
    }

    while(leftIndex <= middleIndex){
        tempArray[mergedIndex] = arr[leftIndex];
        ++leftIndex;
        ++mergedIndex;
    }
    while(rightIndex <= endIndex){
        tempArray[mergedIndex] = arr[rightIndex];
        ++rightIndex;
        ++mergedIndex;
    }
    for(int i =0; i < totalElements; ++i) {
        arr[startInedx + i] = tempArray[i];

    }
    delete[] tempArray;
    return;
};
void MergeSort(int arr[], int startIndex, int endIndex){
    if(startIndex < endIndex){
        int middleIndex = (startIndex + endIndex)/2;

        MergeSort(arr, startIndex, middleIndex);
        MergeSort(arr, middleIndex+1, endIndex);
        Merge(arr, startIndex, middleIndex, endIndex);
    }
    return;
}
int main() {

    //Inicjalizacja tablicy wejściowej
    int arr[] = {15, 34, 25, 45, 23, 56, 85, 34, 23, 11, 9, 5, 78};

    int arrSize = sizeof(arr)/sizeof(*arr);

    std::cout << "Tablica wejściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    MergeSort(arr, 0, arrSize-1);

    std::cout << "Tablica wyjściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
