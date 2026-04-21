#include <stdio.h>

// maximun and minimum of an array using divide and conquer approach

void findMaxMin(int arr[], int low, int high, int *max, int *min){
    if(low == high){ // Only one element .. max=min
        *max = arr[low];
        *min = arr[low];
    }
    else if(high == low + 1){ // Two elements .. compare them
        if(arr[low] < arr[high]){
            *max = arr[high];
            *min = arr[low];
        }
        else{
            *max = arr[low];
            *min = arr[high];
        }
    }
    else{ // More than two elements .. recursion
        int mid = low + (high - low) / 2;
        int max1, min1, max2, min2;

        findMaxMin(arr, low, mid, &max1, &min1);
        findMaxMin(arr, mid + 1, high, &max2, &min2);

        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}

int main(){
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max, min;

    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}