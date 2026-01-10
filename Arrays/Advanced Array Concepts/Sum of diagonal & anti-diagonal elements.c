//For Square Matrix
//Diagonal and anti-diagonal elements are defined only for square matrices.
For a non-square matrix, diagonal sums cannot be computed
#include <stdio.h>

int main() {
    int n;
    int i, j;
    int matrix[10][10];
    int diagSum = 0, antiDiagSum = 0;

    printf("Enter order of the matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate diagonal and anti-diagonal sums
    for (i = 0; i < n; i++) {
        diagSum += matrix[i][i];               // Main diagonal
        antiDiagSum += matrix[i][n - 1 - i];   // Anti-diagonal
    }

    printf("Sum of main diagonal elements = %d\n", diagSum);
    printf("Sum of anti-diagonal elements = %d\n", antiDiagSum);

    return 0;
}
