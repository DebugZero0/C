#include<stdio.h>

void LinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found\n");
}

void BinarySearch(int arr[],int left,int right,int target){
    if(left > right){
        printf("Element not found\n");
        return;
    }
    int mid = left + (right - left) / 2;
    if(arr[mid] == target){
        printf("Element found at index %d\n", mid);
        return;
    }
    if(arr[mid] < target){
        BinarySearch(arr, mid + 1, right, target);
    }
    else{
        BinarySearch(arr, left, mid - 1, target);
    }
}

void main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element_to_search = 30;
    
    // Linear Search
    LinearSearch(arr, size, element_to_search);
    // Binary Search (array must be sorted)
    BinarySearch(arr,0,size-1,element_to_search);
}

// In BS we use mid = left + (right - left) / 2 instead of mid = (left + right) / 2 to avoid potential overflow when left and right are large values. This way, we calculate the mid index without risking integer overflow.

// In BS size -1 because we are passing the last index of the array as the right parameter, and since array indices start at 0, the last index is size - 1.

/*
    Binary search
    worst case : O(log n)
    best case : O(1)
*/