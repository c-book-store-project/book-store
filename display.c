void display(struct node *head)
{
    if(head==NULL)
        printf("\n\n   * the list is empty *\n");
    else
    {
        printf("\n\n \t\t\t                       * the list is *\n");
        printf("                         ***** \n");
    printf("%-20s%-20s %-20s %-20s %-20s\n","ID","TITLE","AUTHOR","GENER","YEAR OF PUPLICATION");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
        while(head!=NULL)
        {
            if(head->number>0){
            printf("\n%-20d %-20s %-20s%-20s%-20d"
                   ,head->id
                   ,head->title
                   ,head->auther_name
                   ,head->gener
                   ,head->year);
            }
            else
                    delfile(head->id);
            head=head->next;
        }
        printf("\n-----------------------------------------------------------------------------------------------------------------");

        puts("\n");
    }
}
