#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, i;
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory is allocated
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Read array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display elements
    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Calculate sum
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("\nSum of elements = %d\n", sum);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
