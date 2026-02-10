#include <stdio.h>
#include <stdlib.h>

// Self-referential structure
struct NODE {
    int data;
    struct NODE *next;
};

// Create node
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

// Remove loop using Floyd’s algorithm
void removeLoop(struct NODE *head) {
    struct NODE *slow = head;
    struct NODE *fast = head;

    // Step 1: Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop
    if (slow != fast)
        return;

    // Step 2: Find start of loop
    slow = head;

    // Special case: loop starts at head
    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    }
    else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Step 3: Remove loop
    fast->next = NULL;
}

// Create loop (for testing)
struct NODE* createLoop(struct NODE *head, int pos) {
    if (head == NULL) return head;

    struct NODE *loopNode = NULL, *temp = head;
    int count = 1;

    while (temp->next != NULL) {
        if (count == pos)
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

    printf("Enter position to create loop (0 for no loop): ");
    scanf("%d", &pos);

    if (pos > 0)
        head = createLoop(head, pos);

    removeLoop(head);

    printf("\nLinked List after removing loop:\n");
    display(head);

    return 0;
}
