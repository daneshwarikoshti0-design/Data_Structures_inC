#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;
    int rows, i, j;
    int *cols;   // stores number of columns for each row

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Allocate memory for row pointers
    arr = (int **)malloc(rows * sizeof(int *));
    cols = (int *)malloc(rows * sizeof(int));

    // Input number of columns for each row
    for (i = 0; i < rows; i++) {
        printf("Enter number of elements in row %d: ", i + 1);
        scanf("%d", &cols[i]);

        // Allocate memory for each row
        arr[i] = (int *)malloc(cols[i] * sizeof(int));
    }

    // Read elements
    printf("Enter elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display jagged array
    printf("\nJagged Array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols[i]; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    free(cols);

    return 0;
}
