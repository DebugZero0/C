#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int arr[MAX], n = 0;
    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) { 
        printf("Error opening input.txt\n");
        return 1;
    }

    // Reading integers from input.txt
    while (fscanf(inputFile, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(inputFile);

    // Sort the array
    sort(arr, n);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output.txt\n");
        return 1;
    }

    // Write sorted integers to output.txt
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fclose(outputFile);

    printf("Sorted data written to output.txt\n");
    return 0;
}
