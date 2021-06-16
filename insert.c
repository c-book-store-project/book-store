void insert(struct node **head,int value, char book_title[], char auther_writer[], char gener_type[], int year_a, int num, float pric)
{
    
    struct node *newnode=malloc(sizeof(struct node));
    
    if (newnode!=NULL)
    {
        newnode->id=value;
        newnode->title=malloc(strlen(book_title)+1);
        strcpy(newnode->title,book_title);
        newnode->auther_name=malloc(strlen(auther_writer)+1);
        strcpy(newnode->auther_name,auther_writer);
        newnode->gener=malloc(strlen(gener_type)+1);
        strcpy(newnode->gener,gener_type);
        newnode->year=year_a;
         newnode->number=num;
        newnode->price=pric;
        newnode->next=NULL;
        struct node *prev=NULL;
        struct node *current=*head;
        while(current!=NULL&&value>current->id)
        {
            prev=current;
            current=current->next;
        }
        if(prev==NULL)
        {
            newnode->next=*head;
            *head=newnode;
        }
        else
        {
            prev->next=newnode;
            newnode->next=current;
        }
    }
    else
    {
        printf("%c not inserted. No memory available.\n", value);
    }
}
