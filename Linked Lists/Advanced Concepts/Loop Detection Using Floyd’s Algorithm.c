#include <stdio.h>
#include <stdlib.h>

// Self-referential structure
struct NODE {
    int data;
    struct NODE *next;
};

// Function to create a new node
struct NODE* createNode(int value) {
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
struct NODE* insertEnd(struct NODE *head, int value) {
    struct NODE *newNode = createNode(value);

    if (head == NULL) {
        return newNode;
    }

    struct NODE *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Display function (only for non-loop list)
void display(struct NODE *head) {
    struct NODE *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Floyd’s Cycle Detection Algorithm
int detectLoop(struct NODE *head) {
    struct NODE *slow = head;
    struct NODE *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast) {
            return 1;   // Loop detected
        }
    }
    return 0;   // No loop
}

// Function to create loop (for testing)
struct NODE* createLoop(struct NODE *head, int position) {
    if (head == NULL) return head;

    struct NODE *loopNode = NULL;
    struct NODE *temp = head;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position)
            loopNode = temp;
        temp = temp->next;
        count++;
    }

    if (loopNode != NULL)
        temp->next = loopNode;

    return head;
}

// Main function
int main() {
    struct NODE *head = NULL;
    int n, value, i, pos;

    printf("How many nodes? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nLinked List:\n");
    display(head);

    printf("\nEnter position to create loop (0 for no loop): ");
    scanf("%d", &pos);

    if (pos > 0)
        head = createLoop(head, pos);

    if (detectLoop(head))
        printf("Loop detected in linked list.\n");
    else
        printf("No loop detected.\n");

    return 0;
}
