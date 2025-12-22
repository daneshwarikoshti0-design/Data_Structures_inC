#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    int arr[100];
    int largest, second_largest;
    int smallest, second_smallest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize
    largest = second_largest = INT_MIN;
    smallest = second_smallest = INT_MAX;

    for (i = 0; i < n; i++) {

        // For largest and second largest
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }

        // For smallest and second smallest
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }

    printf("Second largest element = %d\n", second_largest);
    printf("Second smallest element = %d\n", second_smallest);

    return 0;
}
