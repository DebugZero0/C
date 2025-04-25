#include <stdio.h>
#include <stdlib.h>

void deepCopyArray(int *source, int *destination, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int sourceArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(sourceArray) / sizeof(sourceArray[0]);

    // Allocate memory for the destination array
    int *destinationArray = (int *)malloc(size * sizeof(int));
    if (destinationArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Perform deep copy
    deepCopyArray(sourceArray, destinationArray, size);

    // Print the copied array
    printf("Copied array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", destinationArray[i]);
    }
    printf("\n");

    // Free allocated memory
    free(destinationArray);

    return 0;
}