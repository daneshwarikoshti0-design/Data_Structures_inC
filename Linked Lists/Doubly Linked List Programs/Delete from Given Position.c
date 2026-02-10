struct NODE* deletePosition(struct NODE *head,int pos){
    if(head==NULL)
        return NULL;

    struct NODE *temp=head;

    if(pos==1){
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        free(temp);
        return head;
    }

    for(int i=1;i<pos && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL){
        printf("Invalid Position\n");
        return head;
    }

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    if(temp->prev!=NULL)
        temp->prev->next=temp->next;

    free(temp);
    return head;
}
