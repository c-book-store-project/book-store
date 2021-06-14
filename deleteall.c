void delall(struct node **head){
struct node *temp2=*head;
struct node *temp1;
temp1 = (*head);
while(temp1!=NULL) // as I am considering tail->next = NULL
{
    (*head)->next = temp1->next;
    temp1->next = NULL;
    free(temp1);
    temp1 = (*head)->next;
}
*head=temp2->next;
}
