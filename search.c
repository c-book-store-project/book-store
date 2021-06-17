void search(struct node **head,int val)
{
    struct node *temp=*head;
    if ((*head)->id==val)
    {
        printf("\n  *the book of id (%d) is founded in\n",val);
        printf("     */ ID           -> %d  *\n",(*head)->id);
        printf("     */ title        -> %s  *\n",(*head)->title);
        printf("     */ auther name  -> %s  *\n",(*head)->auther_name);
        printf("     */ gener        -> %s  *\n",(*head)->gener);
        printf("     */ year         -> %d  *\n",(*head)->year);
        printf("     */ num(books)     -> %d  *\n",(*head)->number);
        printf("     */ price          -> %f  *\n",(*head)->price);
    }
    else{
    while(temp->next!=NULL && temp->next->id!=val)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        printf("\n  * not found * \n");
    }
    else
    {
        printf("\n  *the book of id (%d) is founded in\n",val);
        printf("     */ ID           -> %d  *\n",temp->next->id);
        printf("     */ title        -> %s  *\n",temp->next->title);
        printf("     */ auther name  -> %s  *\n",temp->next->auther_name);
        printf("     */ gener        -> %s  *\n",temp->next->gener);
        printf("     */ year         -> %d  *\n",temp->next->year);
        printf("     */ gener        -> %s  *\n",temp->next->gener);
        printf("     */ year         -> %d  *\n",temp->next->year);
    }
    }
}
