#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};

struct NODE* createNode(int val){
    struct NODE* n=(struct NODE*)malloc(sizeof(struct NODE));
    n->data=val;
    n->prev=n->next=NULL;
    return n;
}

struct NODE* insertPosition(struct NODE* head,int val,int pos){
    struct NODE* newNode=createNode(val);

    if(pos==1){
        newNode->next=head;
        if(head) head->prev=newNode;
        return newNode;
    }

    struct NODE* temp=head;
    for(int i=1;i<pos-1 && temp;i++)
        temp=temp->next;

    if(temp==NULL) return head;

    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next) temp->next->prev=newNode;
    temp->next=newNode;

    return head;
}

void display(struct NODE* head){
    while(head){
        printf("%d <-> ",head->data);
        head=head->next;
    }
}

int main(){
    struct NODE* head=NULL;
    head=insertPosition(head,10,1);
    head=insertPosition(head,20,2);
    head=insertPosition(head,15,2);
    display(head);
}
