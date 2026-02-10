#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
};

void traverse(struct NODE *head){
    if(head==NULL) return;

    struct NODE *temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=head);

    printf("(HEAD)\n");
}
