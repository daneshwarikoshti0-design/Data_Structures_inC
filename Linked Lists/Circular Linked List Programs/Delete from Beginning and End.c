#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

// Function to create a new node
struct NODE* createNode(int val) {
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to build the list by adding at the end
struct NODE* insertEnd(struct NODE* head, int val) {
    struct NODE* newNode = createNode(val);
    if (head == NULL) {
        newNode->next = newNode; // Points to itself
        return newNode;
    }
    struct NODE* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Function to display the list
void display(struct NODE* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct NODE* temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}

// DELETE FROM BEGINNING
struct NODE* deleteBeg(struct NODE* head) {
    if (!head) {
        printf("List already empty!\n");
        return NULL;
    }
    struct NODE *temp = head, *last = head;

    // Case: Only one node in list
    if (head->next == head) {
        printf("Deleted: %d. List is now empty.\n", head->data);
        free(head);
        return NULL;
    }

    // Find the last node to update its next pointer
    while (last->next != head) {
        last = last->next;
    }
    
    head = head->next;    // Move head to next node
    last->next = head;    // Last node now points to new head
    printf("Deleted from beginning: %d\n", temp->data);
    free(temp);
    return head;
}

// DELETE FROM END
struct NODE* deleteEnd(struct NODE* head) {
    if (!head) {
        printf("List already empty!\n");
        return NULL;
    }
    struct NODE *curr = head, *prev = NULL;

    // Case: Only one node in list
    if (head->next == head) {
        printf("Deleted: %d. List is now empty.\n", head->data);
        free(head);
        return NULL;
    }

    // Traverse to find the last node (curr) and second-to-last (prev)
    while (curr->next != head) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = head; // Second-to-last node now points to head
    printf("Deleted from end: %d\n", curr->data);
    free(curr);
    return head;
}

int main() {
    struct NODE* head = NULL;
    int n, val, choice;

    // Step 1: User creates the initial list
    printf("--- Create Your Circular Linked List ---\n");
    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    // Step 2: Interactive deletion menu
    while (1) {
        printf("\nCurrent ");
        display(head);
        printf("\n1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            head = deleteBeg(head);
        } else if (choice == 2) {
            head = deleteEnd(head);
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
