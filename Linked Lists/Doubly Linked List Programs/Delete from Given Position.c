#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *prev, *next;
};

// ... (createNode and insertEnd functions same as above) ...
struct NODE* createNode(int val) {
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = val; newNode->prev = newNode->next = NULL;
    return newNode;
}

struct NODE* insertEnd(struct NODE* head, int val) {
    struct NODE* newNode = createNode(val);
    if (!head) return newNode;
    struct NODE* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode; newNode->prev = temp;
    return head;
}

struct NODE* deleteAtPos(struct NODE* head, int pos) {
    if (!head) return NULL;
    struct NODE* temp = head;

    if (pos == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }

    for (int i = 1; temp != NULL && i < pos; i++) temp = temp->next;

    if (!temp) { printf("Position invalid!\n"); return head; }

    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;

    free(temp);
    printf("Node at position %d deleted.\n", pos);
    return head;
}

int main() {
    struct NODE* head = NULL;
    int n, val, pos;

    printf("How many nodes? ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Value: "); scanf("%d", &val);
        head = insertEnd(head, val);
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);
    head = deleteAtPos(head, pos);

    printf("Final List: ");
    while(head) { printf("%d ", head->data); head = head->next; }
    return 0;
}
