#include <stdio.h>

int main() {
    int n, i, sum = 0;  // n is the number of elements and sum is initialized to 0.
    int arr[100];            //arr[100] stores the array elements.

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum of array elements = %d\n", sum);

    return 0;
}
