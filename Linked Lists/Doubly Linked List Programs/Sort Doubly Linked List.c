#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *prev, *next;
};

void sortList(struct NODE* head) {
    int swapped, tempVal;
    struct NODE *ptr1;
    struct NODE *lptr = NULL;

    if (head == NULL) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) { 
                // Swap data
                tempVal = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tempVal;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    struct NODE *n1 = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE *n2 = (struct NODE*)malloc(sizeof(struct NODE));
    struct NODE *n3 = (struct NODE*)malloc(sizeof(struct NODE));
    n1->data = 50; n2->data = 10; n3->data = 30;
    n1->next = n2; n2->prev = n1; n2->next = n3; n3->prev = n2; n3->next = NULL;

    printf("Before Sort: 50, 10, 30\n");
    sortList(n1);
    
    printf("After Sort: ");
    struct NODE* t = n1;
    while(t) { printf("%d ", t->data); t = t->next; }
    return 0;
}
