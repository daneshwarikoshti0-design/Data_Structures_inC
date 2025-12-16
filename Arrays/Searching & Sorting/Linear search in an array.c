//Linear search checks each element sequentially.
//Search stops when the element is found or the array ends.
#include <stdio.h>
int main() {
    int n, i, key;
    int arr[100];
    int found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear search
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the array\n", key);
    }
    return 0;
}
