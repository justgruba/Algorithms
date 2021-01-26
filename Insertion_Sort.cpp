/* Sortowanie przez wstawianie polega na dzieleniu tablicy na podtablice posortowanych i nieposortowanych
 elementów. Wybiera się jeden element odniesienia i iteruje po posortowanej liście na podstawie porównywania
 wartości elementów. W najlepszym przypadku złożoność czasowa tego elgorytmu wynosi O(n)*/
#include <iostream>
void InsertionSort(int *arr, int arrSize){
    int count=0;
    //iteruje po wszystkich elementach tablicy
    for(int i=0; i < arrSize; i++){

        //określa element odniesienia
         int refValue= arr[i];  //O(1)


         int j;

         //iteruje po posortowanych elementach w lewej cześci tablicy
         for( j = i-1; j>=0; j--){
            count++;
             //jeśli element odniesienia jest mniejszy niż posortowane wartości, przesuwa je w prawo
             //jeśli została znaleziona pozycja elementu odniesienia zewnętrzna pętla jest przerywana
             if(arr[j] > refValue)
                 arr[j+1] = arr[j];
             else
                 break;
         }
         //umieszczenie elementu odniesienia na właściwej pozycji
         arr[j+1] = refValue;
    }
std::cout << count << std::endl;
}
int main() {

    //Inicjalizacja tablicy wejściowej
    int arr[] = {1,2,3,4};

    int arrSize = sizeof(arr)/sizeof(*arr);

    std::cout << "Tablica wejściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    InsertionSort(arr, arrSize);

    std::cout << "Tablica wyjściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
