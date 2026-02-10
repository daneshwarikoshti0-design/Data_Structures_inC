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

// Get length
int length(struct NODE *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Left rotate
struct NODE* rotateLeft(struct NODE *head, int k) {
    if (head == NULL || k == 0)
        return head;

    int len = length(head);
    k = k % len;
    if (k == 0)
        return head;

    struct NODE *temp = head;
    int count = 1;

    while (count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }

    struct NODE *newHead = temp->next;
    temp->next = NULL;

    struct NODE *last = newHead;
    while (last->next != NULL)
        last = last->next;

    last->next = head;

    return newHead;
}

// Right rotate
struct NODE* rotateRight(struct NODE *head, int k) {
    if (head == NULL || k == 0)
        return head;

    int len = length(head);
    k = k % len;
    if (k == 0)
        return head;

    return rotateLeft(head, len - k);
}

// Main
int main() {
    struct NODE *head = NULL;
    int n, value, i, k, choice;

    printf("How many nodes? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List:\n");
    display(head);

    printf("\n1. Left Rotate\n2. Right Rotate\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter rotation count k: ");
    scanf("%d", &k);

    if (choice == 1)
        head = rotateLeft(head, k);
    else if (choice == 2)
        head = rotateRight(head, k);
    else
        printf("Invalid choice\n");

    printf("\nList after rotation:\n");
    display(head);

    return 0;
}
