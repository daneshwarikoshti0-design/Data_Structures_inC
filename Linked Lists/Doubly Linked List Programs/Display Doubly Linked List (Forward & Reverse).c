#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};

struct NODE* createNode(int val){
    struct NODE* newNode=(struct NODE*)malloc(sizeof(struct NODE));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

void displayForward(struct NODE* head){
    while(head!=NULL){
        printf("%d <-> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

void displayReverse(struct NODE* head){
    if(head==NULL) return;
    while(head->next!=NULL)
        head=head->next;

    while(head!=NULL){
        printf("%d <-> ",head->data);
        head=head->prev;
    }
    printf("NULL\n");
}

int main(){
    struct NODE *head=NULL,*temp;
    int n,val;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&val);
        temp=createNode(val);
        temp->next=head;
        if(head!=NULL) head->prev=temp;
        head=temp;
    }

    displayForward(head);
    displayReverse(head);
}
