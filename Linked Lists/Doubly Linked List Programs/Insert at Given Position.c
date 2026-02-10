struct NODE* insertPosition(struct NODE *head,int val,int pos){
    struct NODE *newNode=createNode(val);

    if(pos==1){
        newNode->next=head;
        if(head!=NULL)
            head->prev=newNode;
        return newNode;
    }

    struct NODE *temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++)
        temp=temp->next;

    if(temp==NULL){
        printf("Invalid Position\n");
        return head;
    }

    newNode->next=temp->next;
    newNode->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;

    return head;
}
