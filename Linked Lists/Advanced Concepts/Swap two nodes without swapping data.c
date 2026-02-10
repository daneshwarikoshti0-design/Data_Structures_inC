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

// Swap nodes without swapping data
struct NODE* swapNodes(struct NODE *head, int x, int y) {

    if (x == y)
        return head;

    struct NODE *prevX = NULL, *currX = head;
    struct NODE *prevY = NULL, *currY = head;

    // Search for x
    while (currX != NULL && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    // Search for y
    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If not found
    if (currX == NULL || currY == NULL) {
        printf("One or both nodes not found\n");
        return head;
    }

    // Update previous pointers
    if (prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    // Swap next pointers
    struct NODE *temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;
}

// Main function
int main() {
    struct NODE *head = NULL;
    int n, value, i, x, y;

    printf("How many nodes? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    printf("Enter two values to swap: ");
    scanf("%d %d", &x, &y);

    head = swapNodes(head, x, y);

    printf("\nList after swapping nodes:\n");
    display(head);

    return 0;
}
