#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *prev, *next;
};

struct NODE* createNode(int val) {
    struct NODE* n = (struct NODE*)malloc(sizeof(struct NODE));
    n->data = val; n->prev = n->next = NULL;
    return n;
}

// DELETE FROM BEGINNING
struct NODE* deleteBeg(struct NODE* head) {
    if (head == NULL) return NULL;
    struct NODE* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    free(temp);
    printf("Deleted from beginning.\n");
    return head;
}

// DELETE FROM END
struct NODE* deleteEnd(struct NODE* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) { free(head); return NULL; }

    struct NODE* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end.\n");
    return head;
}

void display(struct NODE* head) {
    while (head) { printf("%d <-> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct NODE* head = createNode(10);
    head->next = createNode(20); head->next->prev = head;
    head->next->next = createNode(30); head->next->next->prev = head->next;

    display(head);
    head = deleteBeg(head);
    display(head);
    head = deleteEnd(head);
    display(head);
    return 0;
}
