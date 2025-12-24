#include <stdio.h>

int main() {
    int n, i;
    int arr[100], prefix[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate prefix sum
    prefix[0] = arr[0];
    for (i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    printf("Prefix sum array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", prefix[i]);
    }

    return 0;
}
