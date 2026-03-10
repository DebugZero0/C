#include <stdio.h>

#define MAX_SIZE 100

// Insertion at a given position
void insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE || position < 0 || position > *size) {
        printf("Insertion not possible\n");
        return;
    }
    // For insertion traverse from the end to the position
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}


// Deletion at a given position
void delete(int arr[], int *size, int position) {
    if (*size <= 0 || position < 0 || position >= *size) {
        printf("Deletion not possible\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Search
int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}
// Traversal
void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the operations
int main() {
    int arr[MAX_SIZE];
    int size = 0;

    insert(arr, &size, 10, 0);
    insert(arr, &size, 20, 1);
    insert(arr, &size, 30, 1);
    insert(arr, &size, 40, 1);
    insert(arr, &size, 15, 1);
    printf("Array after insertions: ");
    traverse(arr, size);

    delete(arr, &size, 1);
    printf("Array after deletion: ");
    traverse(arr, size);

    int index = search(arr, size, 20);
    if (index != -1) {
        printf("Element 20 found at index: %d\n", index);
    } else {
        printf("Element 20 not found\n");
    }

    return 0;
}

/*
    Maintaining size is most important for Arrays
*/