#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};

struct NODE* reverse(struct NODE* head){
    struct NODE *temp=NULL,*curr=head;

    while(curr){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }

    if(temp) head=temp->prev;
    return head;
}
