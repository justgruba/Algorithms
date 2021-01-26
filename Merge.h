//
// Created by justyna on 1/26/21.
//

#ifndef MERGE_SORT_MERGE_H
#define MERGE_SORT_MERGE_H


class Merge {
public: void MergeSo(int arr[], int startInedx, int middleIndex, int endIndex) {
        int totalElements = endIndex - startInedx + 1;
        int *tempArray = new int[totalElements];
        int leftIndex = startInedx;
        int rightIndex = middleIndex + 1;
        int mergedIndex = 0;

        while (leftIndex <= middleIndex && rightIndex <= endIndex) {
            if (arr[leftIndex] <= arr[rightIndex]) {
                tempArray[mergedIndex] = arr[leftIndex];
                ++leftIndex;
            } else {
                tempArray[mergedIndex] = arr[rightIndex];
                ++rightIndex;
            }
            ++mergedIndex;
        }

        while (leftIndex <= middleIndex) {
            tempArray[mergedIndex] = arr[leftIndex];
            ++leftIndex;
            ++mergedIndex;
        }
        while (rightIndex <= endIndex) {
            tempArray[mergedIndex] = arr[rightIndex];
            ++rightIndex;
            ++mergedIndex;
        }
        for (int i = 0; i < totalElements; ++i) {
            arr[startInedx + i] = tempArray[i];

        }
        delete[] tempArray;
        return;
    }

    void MergeSort(int arr[], int startIndex, int endIndex){
        if(startIndex < endIndex){
            int middleIndex = (startIndex + endIndex)/2;

            MergeSort(arr, startIndex, middleIndex);
            MergeSort(arr, middleIndex+1, endIndex);
            MergeSo(arr, startIndex, middleIndex, endIndex);
        }
        return;
    }
};


#endif //MERGE_SORT_MERGE_H
