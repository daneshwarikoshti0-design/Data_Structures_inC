#include <stdio.h>
#include <stdlib.h>

// Node structure
struct NODE {
    int data;
    struct NODE *next;
};

struct NODE *top = NULL;

// Push operation
void push(int value) {

    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));

    if (newNode == NULL) {
        printf("Overflow (Memory Full)\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
void pop() {

    if (top == NULL) {
        printf("Underflow (Stack Empty)\n");
        return;
    }

    struct NODE *temp = top;
    printf("Deleted element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

// Display stack
void display() {

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct NODE *temp = top;

    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {

    int choice, value;

    while (1) {

        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
