#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};

struct NODE* createNode(int val){
    struct NODE* newNode=(struct NODE*)malloc(sizeof(struct NODE));
    newNode->data=val;
    newNode->prev=newNode->next=NULL;
    return newNode;
}

struct NODE* insertBeginning(struct NODE* head,int val){
    struct NODE* newNode=createNode(val);
    newNode->next=head;
    if(head!=NULL) head->prev=newNode;
    return newNode;
}

struct NODE* insertEnd(struct NODE* head,int val){
    struct NODE* newNode=createNode(val);
    if(head==NULL) return newNode;

    struct NODE* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

void display(struct NODE* head){
    while(head){
        printf("%d <-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    struct NODE* head=NULL;
    head=insertBeginning(head,10);
    head=insertEnd(head,20);
    head=insertEnd(head,30);
    display(head);
}
