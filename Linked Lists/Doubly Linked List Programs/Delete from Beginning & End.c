struct NODE* deleteBeginning(struct NODE *head){
    if(head==NULL)
        return NULL;

    struct NODE *temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    free(temp);
    return head;
}

struct NODE* deleteEnd(struct NODE *head){
    if(head==NULL)
        return NULL;

    struct NODE *temp=head;

    if(temp->next==NULL){
        free(temp);
        return NULL;
    }

    while(temp->next!=NULL)
        temp=temp->next;

    temp->prev->next=NULL;
    free(temp);

    return head;
}
