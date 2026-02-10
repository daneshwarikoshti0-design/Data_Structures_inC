#include <stdio.h>
#include <stdlib.h>

struct node{ int data; struct node* next; };

int main(){
    struct node *head=NULL,*temp,*newnode,*prev=NULL,*curr,*next;
    int n,i;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL) head=temp=newnode;
        else{ temp->next=newnode; temp=newnode; }
    }

    curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;

    temp=head;
    while(temp){ printf("%d ",temp->data); temp=temp->next; }
}
