#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

struct NODE* insertEnd(struct NODE* head, int val) {
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = val;
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct NODE* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

void display(struct NODE* head) {
    if (!head) return;
    struct NODE* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void splitList(struct NODE* head, struct NODE** head1, struct NODE** head2) {
    if (head == NULL) return;

    struct NODE *slow = head;
    struct NODE *fast = head;

    // Use tortoise and hare algorithm to find the midpoint
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // If even elements, move fast to the last node
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // Set head of first half
    *head1 = head;

    // Set head of second half
    if (head->next != head) {
        *head2 = slow->next;
    }

    // Make second half circular
    fast->next = slow->next;

    // Make first half circular
    slow->next = head;
}

int main() {
    struct NODE *head = NULL, *head1 = NULL, *head2 = NULL;
    int n, val;

    printf("How many nodes to create? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("\nOriginal ");
    display(head);

    if (n < 2) {
        printf("List is too short to split.\n");
    } else {
        splitList(head, &head1, &head2);
        printf("First Half: ");
        display(head1);
        printf("Second Half: ");
        display(head2);
    }

    return 0;
}
