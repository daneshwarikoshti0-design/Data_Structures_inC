#include <stdio.h>
#include <stdlib.h>

// Self-referential structure
struct NODE {
    int data;
    struct NODE *next;
};

// Create a new node
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

// Insert at Beginning
struct NODE* insertBeginning(struct NODE *head, int value) {
    struct NODE *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

// Insert at End
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

// Insert at Specific Position
struct NODE* insertPosition(struct NODE *head, int value, int pos) {
    struct NODE *newNode = createNode(value);

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    struct NODE *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Traverse List
void traverse(struct NODE *head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    struct NODE *temp = head;

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete at Beginning
struct NODE* deleteBeginning(struct NODE *head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return head;
    }

    struct NODE *temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning\n");
    return head;
}

// Delete at End
struct NODE* deleteEnd(struct NODE *head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct NODE *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    printf("Node deleted from end\n");
    return head;
}

// Delete at Specific Position
struct NODE* deletePosition(struct NODE *head, int pos) {
    if (head == NULL) {
        printf("List is Empty\n");
        return head;
    }

    struct NODE *temp = head;

    if (pos == 1) {
        head = temp->next;
        free(temp);
        printf("Node deleted from position %d\n", pos);
        return head;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid Position\n");
        return head;
    }

    struct NODE *del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node deleted from position %d\n", pos);
    return head;
}

// Delete Entire Linked List
struct NODE* deleteEntireList(struct NODE *head) {
    struct NODE *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("Entire Linked List Deleted\n");
    return NULL;
}

// Search an Item
void search(struct NODE *head, int key) {
    struct NODE *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Item %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Item %d not found in list\n", key);
}

// Main Function
int main() {
    struct NODE *head = NULL;
    int choice, value, pos;

    do {
        printf("\n----- Singly Linked List Menu -----");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Traverse List");
        printf("\n5. Delete at Beginning");
        printf("\n6. Delete at End");
        printf("\n7. Delete at Position");
        printf("\n8. Delete Entire List");
        printf("\n9. Search an Item");
        printf("\n10. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertBeginning(head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                head = insertPosition(head, value, pos);
                break;

            case 4:
                traverse(head);
                break;

            case 5:
                head = deleteBeginning(head);
                break;

            case 6:
                head = deleteEnd(head);
                break;

            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deletePosition(head, pos);
                break;

            case 8:
                head = deleteEntireList(head);
                break;

            case 9:
                printf("Enter item to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 10:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 10);

    return 0;
}
