#include <stdio.h>
#include <stdlib.h>

// Node structure
struct NODE {
    int data;
    struct NODE *next;
};

struct NODE *front = NULL;
struct NODE *rear = NULL;

// Enqueue operation
void enqueue(int value) {

    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));

    if (newNode == NULL) {
        printf("Overflow (Memory Full)\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {

    if (front == NULL) {
        printf("Underflow (Queue Empty)\n");
        return;
    }

    struct NODE *temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Display queue
void display() {

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct NODE *temp = front;

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d <- ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {

    int choice, value;

    while (1) {

        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
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
