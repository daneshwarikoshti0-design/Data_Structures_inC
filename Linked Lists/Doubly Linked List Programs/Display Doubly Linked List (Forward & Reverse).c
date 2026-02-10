#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *prev, *next;
};

void displayForward(struct NODE *head) {
    struct NODE *temp = head;
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void displayReverse(struct NODE *head) {
    struct NODE *temp=head;
    if(temp==NULL) return;

    while(temp->next!=NULL)
        temp=temp->next;

    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}
