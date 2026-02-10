#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

// Create node
struct NODE* createNode(int value) {
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct NODE* insertEnd(struct NODE *head, int value) {
    struct NODE *newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct NODE *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Display list
void display(struct NODE *head) {
    struct NODE *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Pairwise swap nodes (without swapping data)
struct NODE* pairwiseSwap(struct NODE *head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct NODE *prev = NULL;
    struct NODE *curr = head;

    head = curr->next;   // new head after first swap

    while (curr != NULL && curr->next != NULL) {

        struct NODE *nextPair = curr->next->next;
        struct NODE *second = curr->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL)
            prev->next = second;

        prev = curr;
        curr = nextPair;
    }

    return head;
}

// Main
int main() {
    struct NODE *head = NULL;
    int n, value, i;

    printf("How many nodes? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    head = pairwiseSwap(head);

    printf("\nList after Pairwise Swap:\n");
    display(head);

    return 0;
}
