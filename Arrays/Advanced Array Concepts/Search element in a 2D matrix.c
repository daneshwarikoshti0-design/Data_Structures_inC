#include <stdio.h>

int main() {
    int r, c;
    int i, j;
    int matrix[10][10];
    int key, found = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear search in 2D matrix
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (matrix[i][j] == key) {
                printf("Element %d found at position (%d, %d)\n",
                       key, i + 1, j + 1);
                found = 1;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        printf("Element %d not found in the matrix.\n", key);

    return 0;
}
