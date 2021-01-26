/* Heap Sort - sortowanie przez kopcowanie
Działanie algorytmu:
1. ułożenie danych tablicowaych w kopiec
2. Usunięcie wierzchłoka z kopca ( jest to najwikszy element) poprzez zamianę go z ostatnim liściem drzewa
3. Przywrócić własnosć kopca
4. Ponowanie usunąc wierzchołek
 Algorytm jest złożoności O(N logN)
*/
#include <iostream>
void heapify(int arr[], int k, int size){
    int i = arr[k-1];

    while(k<= size/2){
        int j = 2*k;
        if( (j<size) && ( arr[j-1] < arr[j]))
            j++;
        if(i>=arr[j-1])
            break;
        arr[k-1] = arr[j-1];
        k=j;
    }
    arr[k-1]=i;
}
void HeapSort(int arr[], int size){
    int swap;
    for(int k=size/2; k>0; k--)
        heapify(arr, k, size);
    do{
        swap=arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = swap;
        size--;
        heapify(arr, 1, size);
    }while(size >1);

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

    HeapSort(arr, arrSize);

    std::cout << "Tablica wyjściowa" << std::endl;
    for(int i=0; i < arrSize; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;


    return 0;
}

