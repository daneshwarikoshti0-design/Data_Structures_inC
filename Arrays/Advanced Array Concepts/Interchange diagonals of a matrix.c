#include <stdio.h>

int main() {
    int n;
    int i, j;
    int matrix[10][10];
    int temp;

    printf("Enter order of the matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Interchange main diagonal and anti-diagonal
    for (i = 0; i < n; i++) {
        temp = matrix[i][i];
        matrix[i][i] = matrix[i][n - 1 - i];
        matrix[i][n - 1 - i] = temp;
    }

    printf("\nMatrix after interchanging diagonals:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
