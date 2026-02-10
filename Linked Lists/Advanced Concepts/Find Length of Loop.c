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

// Display list (only if no loop)
void display(struct NODE *head) {
    struct NODE *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Find length of loop
int loopLength(struct NODE *head) {
    struct NODE *slow = head;
    struct NODE *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 1;
            struct NODE *temp = slow->next;

            while (temp != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;   // No loop
}

// Create loop for testing
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
    int n, value, i, pos, len;

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

    len = loopLength(head);

    if (len > 0)
        printf("Length of loop = %d\n", len);
    else
        printf("No loop detected\n");

    return 0;
}
