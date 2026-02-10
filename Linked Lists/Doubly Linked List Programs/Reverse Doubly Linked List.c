#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *prev, *next;
};

struct NODE* reverse(struct NODE* head) {
    struct NODE *temp = NULL, *curr = head;
    if(!head) return NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; // Move to next node
    }
    if (temp != NULL) head = temp->prev;
    return head;
}

int main() {
    struct NODE *head = NULL, *newNode, *temp;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        newNode = (struct NODE*)malloc(sizeof(struct NODE));
        newNode->data = val; newNode->next = NULL;
        if(!head) { head = newNode; newNode->prev = NULL; }
        else {
            temp = head;
            while(temp->next) temp = temp->next;
            temp->next = newNode; newNode->prev = temp;
        }
    }

    head = reverse(head);
    printf("Reversed List: ");
    while(head) { printf("%d <-> ", head->data); head = head->next; }
    printf("NULL\n");
    return 0;
}
