#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct NODE {
    int coef;
    int exp;
    struct NODE *next;
};

// Create new term
struct NODE* createNode(int c, int e) {
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->coef = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct NODE* insertEnd(struct NODE *head, int c, int e) {
    struct NODE *newNode = createNode(c, e);

    if (head == NULL)
        return newNode;

    struct NODE *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Create polynomial
struct NODE* createPoly() {
    struct NODE *head = NULL;
    int n, c, e, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }

    return head;
}

// Display polynomial
void display(struct NODE *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coef, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

// Add two polynomials
struct NODE* addPoly(struct NODE *p1, struct NODE *p2) {

    struct NODE *result = NULL;

    while (p1 != NULL && p2 != NULL) {

        if (p1->exp == p2->exp) {
            result = insertEnd(result,
                               p1->coef + p2->coef,
                               p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            result = insertEnd(result,
                               p1->coef,
                               p1->exp);
            p1 = p1->next;
        }
        else {
            result = insertEnd(result,
                               p2->coef,
                               p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertEnd(result, p1->coef, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertEnd(result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Main
int main() {

    struct NODE *poly1, *poly2, *result;

    printf("Enter first polynomial:\n");
    poly1 = createPoly();

    printf("Enter second polynomial:\n");
    poly2 = createPoly();

    printf("\nPolynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    result = addPoly(poly1, poly2);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
