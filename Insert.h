
#ifndef INSERTION_SORT_INSERT_H
#define INSERTION_SORT_INSERT_H


class Insert {

public: void InsertionSort(int *arr, int arrSize){

        //iteruje po wszystkich elementach tablicy
        for(int i=0; i < arrSize; i++){

            //określa element odniesienia
            int refValue= arr[i];  //O(1)


            int j;

            //iteruje po posortowanych elementach w lewej cześci tablicy
            for( j = i-1; j>=0; j--){

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

    }
};


#endif //INSERTION_SORT_INSERT_H
