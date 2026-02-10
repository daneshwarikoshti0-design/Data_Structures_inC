#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

struct NODE* createNode(int val) {
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Traverse and Print
void display(struct NODE* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct NODE* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head: %d)\n", head->data);
}

// Insert at Beginning
struct NODE* insertBeg(struct NODE* head, int val) {
    struct NODE* newNode = createNode(val);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    struct NODE* temp = head;
    while (temp->next != head) temp = temp->next; // Find last node
    
    temp->next = newNode;
    newNode->next = head;
    return newNode; // New node becomes head
}

// Insert at End
struct NODE* insertEnd(struct NODE* head, int val) {
    struct NODE* newNode = createNode(val);
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

int main() {
    struct NODE* head = NULL;
    int choice, val;

    while(1) {
        printf("\n1. Insert Beg\n2. Insert End\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 4) break;
        
        printf("Enter value: ");
        scanf("%d", &val);
        if (choice == 1) head = insertBeg(head, val);
        else if (choice == 2) head = insertEnd(head, val);
        display(head);
    }
    return 0;
}
