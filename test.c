int test(struct node **head,int val)
{
    struct node *temp=*head;
    if ((*head)->id==val)
    {
        return 1;
    }
    while(temp->next!=NULL && temp->next->id!=val)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
       
        return 0;
    }
    else
    {
        return 1;
    }
}
