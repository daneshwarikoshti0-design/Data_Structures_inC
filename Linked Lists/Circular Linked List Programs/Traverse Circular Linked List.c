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
}

int main(){
    struct NODE n1={10,NULL},n2={20,NULL},n3={30,NULL};

    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n1;

    traverse(&n1);
}
