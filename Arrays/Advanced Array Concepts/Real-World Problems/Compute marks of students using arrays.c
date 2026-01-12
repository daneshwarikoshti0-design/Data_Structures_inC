#include <stdio.h>

int main() {
    int n, subjects;
    int i, j;
    int marks[50][10];
    int total;
    float average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter number of subjects: ");
    scanf("%d", &subjects);

    // Read marks
    for (i = 0; i < n; i++) {
        printf("\nEnter marks for Student %d:\n", i + 1);
        for (j = 0; j < subjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    // Calculate and display total and average
    printf("\nStudent Results:\n");
    for (i = 0; i < n; i++) {
        total = 0;
        for (j = 0; j < subjects; j++) {
            total += marks[i][j];
        }
        average = (float)total / subjects;

        printf("Student %d -> Total = %d, Average = %.2f\n",
               i + 1, total, average);
    }

    return 0;
}
