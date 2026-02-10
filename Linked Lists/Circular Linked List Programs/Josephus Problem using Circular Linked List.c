#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

// Function to create a circular list of N people
struct NODE* createCircle(int n) {
    struct NODE *head = NULL, *temp = NULL;
    for (int i = 1; i <= n; i++) {
        struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
        newNode->data = i;
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
    return head;
}

void solveJosephus(int n, int k) {
    struct NODE *head = createCircle(n);
    struct NODE *curr = head, *prev = NULL;

    // Find the node before head to start the deletion process
    while (curr->next != head) curr = curr->next;
    prev = curr;
    curr = head;

    printf("\nElimination Order: ");
    while (curr->next != curr) {
        // Count up to K-1 to find the Kth person
        for (int i = 1; i < k; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Remove the Kth node
        prev->next = curr->next;
        printf("%d ", curr->data);
        free(curr);

        // Continue from the person after the one just eliminated
        curr = prev->next;
    }

    printf("\n\nThe Survivor is person: %d\n", curr->data);
    free(curr);
}

int main() {
    int n, k;

    printf("--- Josephus Problem Solver ---\n");
    printf("Enter total number of people (N): ");
    scanf("%d", &n);
    printf("Enter the gap/step for elimination (K): ");
    scanf("%d", &k);

    if (n <= 0 || k <= 0) {
        printf("Invalid input. Please enter values greater than 0.\n");
    } else {
        solveJosephus(n, k);
    }

    return 0;
}
