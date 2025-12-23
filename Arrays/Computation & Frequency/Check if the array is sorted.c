#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int sorted = 1;   // assume array is sorted

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check sorting
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = 0;
            break;
        }
    }

    if (sorted)
        printf("The array is sorted in ascending order.\n");
    else
        printf("The array is NOT sorted.\n");

    return 0;
}
