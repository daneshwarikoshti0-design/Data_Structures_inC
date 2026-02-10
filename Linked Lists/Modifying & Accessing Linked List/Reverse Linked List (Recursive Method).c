#include <stdio.h>
#include <stdlib.h>

struct node{ int data; struct node* next; };

struct node* reverse(struct node* head){
    if(head==NULL || head->next==NULL) return head;
    struct node* rest=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}

int main(){
    struct node *head=NULL,*temp,*newnode;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL) head=temp=newnode;
        else{ temp->next=newnode; temp=newnode; }
    }

    head=reverse(head);

    temp=head;
    while(temp){ printf("%d ",temp->data); temp=temp->next; }
}
