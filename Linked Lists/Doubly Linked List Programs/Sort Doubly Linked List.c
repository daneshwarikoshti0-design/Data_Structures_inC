#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    struct NODE *prev,*next;
};

void sort(struct NODE* head){
    struct NODE *i,*j;
    int temp;

    for(i=head;i;i=i->next){
        for(j=i->next;j;j=j->next){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}
