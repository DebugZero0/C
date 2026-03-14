#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap the pivot element with the element at index i + 1
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(){
    int arr[] = {7,9,6,5,8};
    int n = 5;

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

/*
    Best case: O(n log n) - when the pivot divides the array into two equal halves
    Avg case: O(n log n) - on average, quicksort performs well with random pivots
    Worst case: O(n^2) - when the smallest or largest element is always chosen as the pivot

    NOT STABLE SORTING ALGORITHM
*/