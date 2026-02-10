#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
};

struct NODE* createNode(int val){
    struct NODE* newNode=(struct NODE*)malloc(sizeof(struct NODE));
    newNode->data=val;
    newNode->next=newNode;
    return newNode;
}

struct NODE* createCLL(int n){
    struct NODE *head=NULL,*temp,*last=NULL;
    int val;

    for(int i=0;i<n;i++){
        scanf("%d",&val);
        temp=createNode(val);

        if(head==NULL){
            head=last=temp;
        }else{
            last->next=temp;
            last=temp;
        }
    }
    last->next=head;
    return head;
}

int main(){
    struct NODE *head;
    int n;
    scanf("%d",&n);
    head=createCLL(n);
}
