#include <stdio.h>
#include <stdlib.h>

// Node structure
struct NODE {
    int row, col, value;
    struct NODE *next;
};

// Create node
struct NODE* createNode(int r, int c, int v) {
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->row = r;
    newNode->col = c;
    newNode->value = v;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct NODE* insertEnd(struct NODE *head, int r, int c, int v) {

    struct NODE *newNode = createNode(r, c, v);

    if (head == NULL)
        return newNode;

    struct NODE *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Create sparse matrix
struct NODE* createSparse() {

    struct NODE *head = NULL;
    int rows, cols, i, j, val;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {

            scanf("%d", &val);

            if (val != 0)
                head = insertEnd(head, i, j, val);
        }
    }

    return head;
}

// Display sparse list
void display(struct NODE *head) {

    if (head == NULL) {
        printf("Matrix has all zero elements\n");
        return;
    }

    printf("Row  Col  Value\n");

    while (head != NULL) {
        printf("%d    %d    %d\n",
               head->row,
               head->col,
               head->value);
        head = head->next;
    }
}

// Main
int main() {

    struct NODE *sparseMatrix;

    sparseMatrix = createSparse();

    printf("\nSparse Matrix Representation:\n");
    display(sparseMatrix);

    return 0;
}
