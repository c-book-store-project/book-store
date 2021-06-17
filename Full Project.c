#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
struct node
{
    int id;
    char *title;
    char *auther_name;
    char *gener;
    int year;
    float price;
    int number;
    struct node *next;
};
int t;
void insert(struct node **head,int value, char book_title[], char auther_writer[], char gener_type[], int year_a, int num, float pric);
int delet_id(struct node **head,int value);
int delet_name(struct node **head,char *tit);
void search(struct node **head,int val);
void display(struct node *head);
int test(struct node **head,int val);
int instr(void);
void write(int value, char book_title[], char auther_writer[], char gener_type[], int year_a, int num, float pric );
void delfile(int n);
void delall(struct node **head);
void delallfile(void);
int sell(struct node **head,int value,int n);
int main()
{
    struct node *head=NULL;
    int id=0;
    char title[100];
    char auther_name[100];
    char gener[50];
    int year;
     float price;
    int number;
    int ans;
    int choise;
    char*ptr;
    char str1[1024];
    FILE *f;
    int n;
    int i;
    float tot=0.0;
    if((f=fopen("pop.csv","r"))==NULL)
        printf("file not found");
         while(fgets(str1, sizeof str1, f) !=NULL){
                if ((strlen(str1)>0) && (str1[strlen (str1) - 1] == '\n'))
            str1[strlen (str1) - 1] = '\0';
         ptr=strtok(str1,",");
         id=atoi(ptr);
         ptr=strtok(NULL,",");
         strcpy(title, ptr);
         ptr=strtok(NULL,",");
         strcpy(auther_name,ptr);
         ptr=strtok(NULL,",");
         strcpy(gener,ptr);
         ptr=strtok(NULL,",");
         year=atoi(ptr);
         ptr=strtok(NULL,",");
         number=atoi(ptr);
         ptr=strtok(NULL,",");
         price=atoi(ptr);
         insert(&head,id,title,auther_name,gener,year,number,price);
         i++;
      }
      printf("\n");
      fclose(f);
     system("pause");
//     pass();
      system("cls");
    while((choise=instr())!=7)
    {
system("cls");
        switch (choise)
        {
        case 1:
            printf("\n  enter id of book: ");
            scanf("%d",&id);
    fflush(stdin);
            if(head!=NULL){
            while(test(&head,id)){
                printf("  * this ID is used or wrong Please enter another ID: ");
                scanf("%d",&id);
                fflush(stdin);
            }
            }
//            fgetc(stdin);
            printf("  Enter title of book: ");
            fgets(title, 100,stdin);
            if( title[strlen(title)-1] == '\n' )
                title[strlen(title)-1] = 0;
            printf("  Enter auther of book: ");
            fgets(auther_name, 100, stdin);
            if( auther_name[strlen(auther_name)-1] == '\n' )
                auther_name[strlen(auther_name)-1] = 0;
            printf("  Enter the gener of book: ");
            fgets(gener, 100, stdin);
            if( gener[strlen(gener)-1] == '\n' )
                gener[strlen(gener)-1] = 0;
            printf("  Enter the year of book publish: ");
            scanf("%d",&year);
            printf("  Enter Number of book: ");
            scanf("%d",&number);
            printf("  Enter the price of book: ");
            scanf("%f",&price);
            fflush(stdin);
            write(id,title,auther_name,gener,year,number,price);
            insert(&head,id,title,auther_name,gener,year,number,price);
            printf("\n     * this book is correctly inserted *\n");
            break;
        case 2:
            if(head!=NULL)
            {
                printf(" ENTER ID of book to search it: ");
                scanf("%d",&id);
                search(&head,id);
            }
            else
                printf("\n    * the list is empty * \n");
            break;
        case 3:
                if(head!=NULL)
                {
                    printf("      * what do you want to delete *\n  1)-all\t\t2-)spetial book\n");
                    do{
                    printf("enter your choise: ");
                    scanf("%d",&ans);
                   }while(ans!=1&&ans!=2);
                      if(ans==2){
                    printf("\n   Enter ID of book to delete: ");
                    scanf("%d",&id);
                    if(delet_id(&head,id))
                    {
                        printf("\n\n    * ID of number %d is deleted. *\n\n",id);
                    }
                    else printf("\n\n   * ID of number %d is not found *\n\n",id);
                }
                else{
                    delall(&head);
                    delallfile();
                printf("\n  * all book is deleted *\n");
                }
                }
                else
                    printf("\n\n     * the list is empty *\n");
            break;
        case 4:
            if(head!=NULL)
            {
                printf("  Enter the id of book you want update: ");
                scanf("%d",&id);
                if(test(&head,id)==1)
                {
                    delet_id(&head,id);
                    delfile(id);
                    fgetc(stdin);
                    printf("Enter new title of book: ");
                    fgets(title, 100,stdin);
                    if( title[strlen(title)-1] == '\n' )
                        title[strlen(title)-1] = 0;
                    printf("Enter new auther of book: ");
                    fgets(auther_name, 100, stdin);
                    if( auther_name[strlen(auther_name)-1] == '\n' )
                        auther_name[strlen(auther_name)-1] = 0;
                    printf("Enter the new gener of book: ");
                    fgets(gener, 100, stdin);
                    if( gener[strlen(gener)-1] == '\n' )
                        gener[strlen(gener)-1] = 0;
                    printf("Enter the new year of book publish: ");
                    scanf("%d",&year);
                     printf("Enter new Number of book: ");
                    scanf("%d",&number);
                    printf("Enter new price of book: ");
                    scanf("%f",&price);
                    write(id,title,auther_name,gener,year,number,price);
                    insert(&head,id,title,auther_name,gener,year,number,price);
                    printf("\n    * this book is correctly upgrade *\n");
                }
                else
                    printf("\n     * not found * \n");
            }
            else
                printf("\n   * the list is empty *\n");
            break;
        case 5:
            display(head);
            break;
        case 6:
            if(head!=NULL){
            printf("  Enter id of sell book press (-1) to end: ");
            scanf("%d",&id);
            printf("number of books you want sell: ");
            scanf("%d",&n);
            delfile(id);
            tot=sell(&head,id,n);
            printf("\n    * total price is %f *\n",tot);
             }
            else
                 printf("\n   * the list is empty *\n");
            break;
        default:
            printf("invalid choise");
            break;
        }
    }
    printf("\n       * end program *\n");
}
int instr(void)
{
    printf("\n   *************\n");
    printf("   *         * Book Data Base *        *\n");
    printf("   *************\n");
    printf("%s", "\nEnter your choice\n"
           "     1 - INSERT BOOK DETAILES\n"
           "     2 - SEARCH OF BOOK\n"
           "     3 - DELETE OF BOOK\n"
           "     4 - UPDATE BOOK DETAILES\n"
           "     5 - DISPLAY ALL BOOKS DETAILES\n"
           "     6 - SELL BOOKS\n"
           "     7 - TO SAVE CHANGE\n");
    unsigned int menuChoice;
    printf("%s", "? ");
    scanf("%u", &menuChoice);
    return menuChoice;
}
void insert(struct node **head,int value, char book_title[], char auther_writer[], char gener_type[], int year_a , int num, float pric)
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
            printf("\n  %d\t\t%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%f"
                   ,head->id
                   ,head->title
                   ,head->auther_name
                   ,head->gener
                   ,head->year
                   ,head->number
                   ,head->price);
            head=head->next;
            printf("\n----------------------------------------------------------------------------------------------------------");
        }
        puts("\n");
    }
}
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
void delall(struct node **head){
struct node *temp2=*head;
struct node *temp1;
temp1 = (*head);
while(temp1!=NULL) // as I am considering tamp->next = NULL
{
    (*head)->next = temp1->next;
    temp1->next = NULL;
    free(temp1);
    temp1 = (*head)->next;
}
*head=temp2->next;
}
void search(struct node **head,int val)
{
    struct node *temp=*head;
    if ((*head)->id==val)
    {
        printf("\n  *the book of id (%d) is founded in\n",val);
        printf("     */ ID             -> %d  *\n",(*head)->id);
        printf("     */ title          -> %s  *\n",(*head)->title);
        printf("     */ auther name    -> %s  *\n",(*head)->auther_name);
        printf("     */ gener          -> %s  *\n",(*head)->gener);
        printf("     */ year           -> %d  *\n",(*head)->year);
        printf("     */ num(books)     -> %d  *\n",(*head)->number);
        printf("     */ price          -> %f  *\n",(*head)->price);
    }
    else{
    temp=*head;
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
    }
    }
}
int test(struct node **head,int val)
{
    t=0;
    struct node *temp=*head;
    if ((*head)->id==val)
    {
        return 1;
    }
    else{
    temp=*head;
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
}
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
void write(int value, char book_title[], char auther_writer[], char gener_type[], int year_a, int num, float pric){
FILE *f=fopen("pop.csv","a+");
if(f==NULL)
    printf("file not found");
else{
    fprintf(f,"%d,%s,%s,%s,%d,%d,%f\n",value,book_title,auther_writer,gener_type,year_a,num,pric);
}
}
void delfile(int n){
FILE *f=fopen("pop.csv","r");
FILE *f2=fopen("popcp.csv","a");
    int id;
    char title[100];
    char auther_name[100];
    char gener[50]={0};
    int year=0;
    float price;
    int number;
    char*ptr;
    char str1[1024];
if(f==NULL)
    printf("file not exist");
     while(fgets(str1, sizeof str1, f) !=NULL){
                if ((strlen(str1)>0) && (str1[strlen (str1) - 1] == '\n'))
            str1[strlen (str1) - 1] = '\0';
         ptr=strtok(str1,",");
         id=atoi(ptr);
         ptr=strtok(NULL,",");
         strcpy(title, ptr);
         ptr=strtok(NULL,",");
         strcpy(auther_name,ptr);
         ptr=strtok(NULL,",");
         strcpy(gener,ptr);
         ptr=strtok(NULL,",");
         year=atoi(ptr);
         ptr=strtok(NULL,",");
         number=atoi(ptr);
         ptr=strtok(NULL,",");
         price=atoi(ptr);
    if(id != n){
      fprintf(f2,"%d,%s,%s,%s,%d,%d,%f\n",id,title,auther_name,gener,year,number,price);
    }
    }
fclose(f);
fclose(f2);
remove("pop.csv");
rename("popcp.csv","pop.csv");
}
void delallfile(void){
FILE *f2=fopen("popcp.csv","a");
fclose(f2);
remove("pop.csv");
rename("popcp.csv","pop.csv");
}