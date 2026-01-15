#include <stdio.h>

int main() {
    int n, i, j;
    int marks[50];
    int rank[50];
    int temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter marks of students:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
        rank[i] = i + 1;    // store student number
    }

    // Sorting marks in descending order (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (marks[j] < marks[j + 1]) {

                // swap marks
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;

                // swap student numbers
                temp = rank[j];
                rank[j] = rank[j + 1];
                rank[j + 1] = temp;
            }
        }
    }

    // Display leaderboard
    printf("\nLEADERBOARD RANK LIST\n");
    printf("Rank\tStudent\tMarks\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, rank[i], marks[i]);
    }

    return 0;
}
