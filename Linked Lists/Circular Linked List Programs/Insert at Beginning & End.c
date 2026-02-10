#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
};

struct NODE* createNode(int val){
    struct NODE* n=(struct NODE*)malloc(sizeof(struct NODE));
    n->data=val;
    n->next=n;
    return n;
}

struct NODE* insertBeginning(struct NODE* head,int val){
    struct NODE* newNode=createNode(val);

    if(head==NULL) return newNode;

    struct NODE* temp=head;
    while(temp->next!=head)
        temp=temp->next;

    newNode->next=head;
    temp->next=newNode;
    return newNode;
}

struct NODE* insertEnd(struct NODE* head,int val){
    struct NODE* newNode=createNode(val);

    if(head==NULL) return newNode;

    struct NODE* temp=head;
    while(temp->next!=head)
        temp=temp->next;

    temp->next=newNode;
    newNode->next=head;
    return head;
}

void display(struct NODE* head){
    if(head==NULL) return;
    struct NODE* temp=head;
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

int main(){
    struct NODE* head=NULL;

    head=insertBeginning(head,20);
    head=insertBeginning(head,10);
    head=insertEnd(head,30);

    display(head);
}
