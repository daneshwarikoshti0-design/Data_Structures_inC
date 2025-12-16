#include <stdio.h>
int main() {
    int n, i;
    int arr[100];
    int positive = 0, negative = 0;
    int even = 0, odd = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Check positive or negative
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;

        // Check even or odd
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("\nPositive numbers = %d", positive);
    printf("\nNegative numbers = %d", negative);
    printf("\nEven numbers     = %d", even);
    printf("\nOdd numbers      = %d", odd);

    return 0;
}
