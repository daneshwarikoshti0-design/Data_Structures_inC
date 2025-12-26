#include <stdio.h>

int main() {
    int n, i;
    int arr1[100], arr2[100], diff[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements of first array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter %d elements of second array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    // Calculate element-wise difference
    for (i = 0; i < n; i++) {
        diff[i] = arr1[i] - arr2[i];
    }

    printf("Difference array (arr1 - arr2):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", diff[i]);
    }

    return 0;
}
