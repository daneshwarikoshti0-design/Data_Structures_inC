#include <stdio.h>

int main() {
    int r, c;
    int i, j;
    int matrix[10][10];
    int rowSum, colSum;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sum of each row
    printf("\nSum of each row:\n");
    for (i = 0; i < r; i++) {
        rowSum = 0;
        for (j = 0; j < c; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, rowSum);
    }

    // Sum of each column
    printf("\nSum of each column:\n");
    for (j = 0; j < c; j++) {
        colSum = 0;
        for (i = 0; i < r; i++) {
            colSum += matrix[i][j];
        }
        printf("Column %d sum = %d\n", j + 1, colSum);
    }

    return 0;
}
