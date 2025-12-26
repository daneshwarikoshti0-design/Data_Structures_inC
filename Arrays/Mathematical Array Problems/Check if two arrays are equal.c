#include <stdio.h>

int main() {
    int n1, n2, i;
    int arr1[100], arr2[100];
    int equal = 1;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements of first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements of second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Check size first
    if (n1 != n2) {
        equal = 0;
    } else {
        // Compare elements
        for (i = 0; i < n1; i++) {
            if (arr1[i] != arr2[i]) {
                equal = 0;
                break;
            }
        }
    }

    if (equal)
        printf("The two arrays are equal.\n");
    else
        printf("The two arrays are NOT equal.\n");

    return 0;
}
