#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int index = 0;   // position for non-zero elements

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Move non-zero elements forward
    for (i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[index] = arr[i];
            index++;
        }
    }

    // Fill remaining positions with zeros
    while (index < n) {
        arr[index] = 0;
        index++;
    }

    printf("Array after shifting zeros to the end:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
