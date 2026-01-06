#include <stdio.h>

int main() {
    int matrix[10][10];
    int sparse[20][3];
    int r, c;
    int i, j, k = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Store matrix size temporarily
    sparse[0][0] = r;
    sparse[0][1] = c;

    // Convert to sparse form
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Store number of non-zero elements
    sparse[0][2] = k - 1;

    printf("\nSparse Matrix Representation:\n");
    printf("Row  Col  Value\n");
    for (i = 0; i < k; i++) {
        printf("%d    %d    %d\n",
               sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
