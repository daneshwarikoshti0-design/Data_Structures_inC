#include <stdio.h>

int main() {
    int r, c;
    int i, j;
    int matrix[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nWave print of the matrix:\n");
    for (i = 0; i < r; i++) {
        if (i % 2 == 0) {
            // Left to right
            for (j = 0; j < c; j++) {
                printf("%d ", matrix[i][j]);
            }
        } else {
            // Right to left
            for (j = c - 1; j >= 0; j--) {
                printf("%d ", matrix[i][j]);
            }
        }
    }

    return 0;
}
