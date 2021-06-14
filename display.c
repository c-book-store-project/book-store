void display(struct node *head)
{
    if(head==NULL)
        printf("\n\n   * the list is empty *\n");
    else
    {
        printf("\n\n                        * the list is *\n");
        printf("                         ***** \n");
//    printf("ID           title           auther            gener             (year of publish)\n");
//    printf("---------------------------------------------------------------------------\n");
        while(head!=NULL)
        {
            printf("\n  %d\t\t%s\t\t%s\t\t%s\t\t%d"
                   ,head->id
                   ,head->title
                   ,head->auther_name
                   ,head->gener
                   ,head->year);
            head=head->next;
            printf("\n----------------------------------------------------------------------------");
        }
        puts("\n");
    }
}
