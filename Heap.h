//
// Created by justyna on 1/26/21.
//

#ifndef HEAP_SORT_HEAP_H
#define HEAP_SORT_HEAP_H


class Heap {
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
};


#endif //HEAP_SORT_HEAP_H
