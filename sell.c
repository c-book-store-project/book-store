int sell(struct node **head,int value,int n){
   struct node *temp=*head;
   int ans;
    if ((*head)->id==value)
    {
        printf("\n  *the book of id (%d) is founded in\n",value);
        printf("  title of this book is       -> %s  *\n",(*head)->title);
        printf("  num(books) of this book     -> %d  *\n",(*head)->number);
        printf("  price of this book          -> %f  *\n",(*head)->price);
    printf("\n press (1) to ensure selling of this book or (0) to cancel this operate: ");
    scanf("%d",&ans);
    while(ans!=1 && ans!=0){
    printf("\n press (1) to ensure selling of this book or (0) to cancel this operation: ");
    scanf("%d",&ans);
    }
    if(ans==1){
        printf("\n   * this book is sell *\n\n");
        (*head)->number-=n;
         write((*head)->id,(*head)->title,(*head)->auther_name,(*head)->gener,(*head)->year,(*head)->number,(*head)->price);
    return ((*head)->price)*n;
    }
    else
        printf("\n   * this operate is canceled *\n\n");
    }
    else{
    temp=*head;
    while(temp->next!=NULL && temp->next->id!=value)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        printf("\n  * this book is not found * \n");
    }
    else
    {
        printf("\n  *the book of id (%d) is founded in\n",value);
        printf("  title of this book is       -> %s  *\n",temp->next->title);
        printf("  num(books) of this book     -> %d  *\n",temp->next->number);
        printf("  price of this book          -> %f  *\n",temp->next->price);
       printf("\n press (1) to ensure selling of this book or (0) to cancel this operate: ");
       scanf("%d",&ans);
       while(ans!=1 && ans!=0){
       printf("\n press (1) to ensure selling of this book or (0) to cancel this operation: ");
      scanf("%d",&ans);
      }
      if(ans==1){
        printf("\n   * this book is sell *\n\n");
         temp->next->number-=n;
         write(temp->next->id,temp->next->title,temp->next->auther_name,temp->next->gener,temp->next->year,temp->next->number,temp->next->price);
     return ((temp->next)->price)*n;
    }
    else
        printf("\n   * this operate is canceled *\n\n");
    }
    }
}
