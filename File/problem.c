#include <stdio.h>

int main() {
    FILE *file;
    int n, i, num;

    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter how many integers you want to store: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        fprintf(file, "%d ", num);
    }

    fclose(file);
    printf("Data successfully written to input.txt\n");
    return 0;
}
