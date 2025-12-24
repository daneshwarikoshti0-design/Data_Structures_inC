#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int evenIndexSum = 0, oddIndexSum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sums
    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            evenIndexSum += arr[i];
        else
            oddIndexSum += arr[i];
    }

    printf("Sum of elements at even indices = %d\n", evenIndexSum);
    printf("Sum of elements at odd indices  = %d\n", oddIndexSum);

    return 0;
}
