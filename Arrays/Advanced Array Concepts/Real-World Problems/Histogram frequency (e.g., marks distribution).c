#include <stdio.h>

int main() {
    int n, i;
    int marks[50];
    int freq[11] = {0};   // 11 ranges: 0-9,10-19,...,90-99,100
    int index;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks (0 to 100):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);

        // Determine range index
        if (marks[i] == 100)
            index = 10;
        else
            index = marks[i] / 10;

        freq[index]++;
    }

    // Display histogram frequency
    printf("\nMarks Distribution Histogram:\n");

    for (i = 0; i < 10; i++) {
        printf("%2d - %2d : %d\n", i * 10, i * 10 + 9, freq[i]);
    }

    printf("100      : %d\n", freq[10]);

    return 0;
}
