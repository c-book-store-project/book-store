int delet_id(struct node **head,int value)
{
    struct node *temp1=NULL;
    struct node *temp2=NULL;
    if(head==NULL||*head==NULL)return 0;
    if((*head)->id==value)
    {
        temp1=*head;
        *head=(*head)->next;
        free(temp1);
        delfile(value);
        return 1;
    }
    temp1=*head;
    while(temp1->next!=NULL && temp1->next->id != value)
    {
        temp1=temp1->next;
    }
    if(temp1->next==NULL)return 0;
    else
    {
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
         delfile(value);
        return 1;
    }
} 

