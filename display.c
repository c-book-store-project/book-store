void display(struct node *head)
{
    if(head==NULL)
        printf("\n\n   * the list is empty *\n");
    else
    {
        printf("\n\n \t\t\t                       * the list is *\n");
        printf("                         ***** \n");
    printf("%-20s%-20s %-20s %-20s %-20s %-20s %-10s\n","ID","TITLE","AUTHOR","GENER","YEAR OF PUPLICATION", "books number","price" );
    printf("-------------------------------------------------------------------------------------------------------------------\n");
        while(head!=NULL)
        {
            if(head->number>0){
            printf("\n%-20d %-20s %-20s%-20s%-20d %-20d %-10.2f"
                   ,head->id
                   ,head->title
                   ,head->auther_name
                   ,head->gener
                   ,head->year,
                   head->number
                   ,head->price);
            }
            else
                    delfile(head->id);
            head=head->next;
        }
        printf("\n-----------------------------------------------------------------------------------------------------------------");

        puts("\n");
    }
}
