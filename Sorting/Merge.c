#include <stdio.h>

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2]; // Temporary arrays to hold the left and right subarrays

    // Copy data to temp arrays
    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge the temp arrays back into arr[l..r]
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){ // Stable sorting condition
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

/*
    Best case: O(n log n) - merge sort always divides the array into two halves and takes linear time to merge them
    Avg case: O(n log n) - on average, merge sort performs well regardless of the input distribution
    Worst case: O(n log n) - merge sort's performance is consistent across all cases

    STABLE SORTING ALGORITHM
*/