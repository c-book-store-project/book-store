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
    struct node *next;
};
int t;
void insert(struct node **head,int value, char book_title[], char auther_writer[], char gener_type[], int year_a);
int delet_id(struct node **head,int value);
int delet_name(struct node **head,char *tit);
void search(struct node **head,int val);
void display(struct node *head);
int test(struct node **head,int val);
int instr(void);
int open(void);
void write(int value, char book_title[], char auther_writer[], char gener_type[], int year_a);
void delfile(int n);
void delall(struct node **head);
void delallfile(void);
int main()
{
    struct node *head=NULL;
    int id=0;
    char title[100];
    char auther_name[100];
    char gener[50];
    int year;
    int ans;
    int choise;
    char*ptr;
    char str1[1024];
    FILE *f;
    int i;
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
         insert(&head,id,title,auther_name,gener,year);
         i++;
      }
      printf("\n");
      fclose(f);
     system("pause");
    while((choise=instr())!=6)
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
            printf("  enter title of book: ");
            fgets(title, 100,stdin);
            if( title[strlen(title)-1] == '\n' )
                title[strlen(title)-1] = 0;
            printf("  enter auther of book: ");
            fgets(auther_name, 100, stdin);
            if( auther_name[strlen(auther_name)-1] == '\n' )
                auther_name[strlen(auther_name)-1] = 0;
            printf("  enter the gener of book: ");
            fgets(gener, 100, stdin);
            if( gener[strlen(gener)-1] == '\n' )
                gener[strlen(gener)-1] = 0;
            printf("  enter the year of book publish: ");
            scanf("%d",&year);
            fflush(stdin);
            write(id,title,auther_name,gener,year);
            insert(&head,id,title,auther_name,gener,year);
            printf("\n    * this book is correctly inserted *\n");
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
                    printf("enter title of book: ");
                    fgets(title, 100,stdin);
                    if( title[strlen(title)-1] == '\n' )
                        title[strlen(title)-1] = 0;
                    printf("enter new auther of book: ");
                    fgets(auther_name, 100, stdin);
                    if( auther_name[strlen(auther_name)-1] == '\n' )
                        auther_name[strlen(auther_name)-1] = 0;
                    printf("enter the new gener of book: ");
                    fgets(gener, 100, stdin);
                    if( gener[strlen(gener)-1] == '\n' )
                        gener[strlen(gener)-1] = 0;
                    printf("enter the new year of book publish: ");
                    scanf("%d",&year);
                    write(id,title,auther_name,gener,year);
                    insert(&head,id,title,auther_name,gener,year);
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
        default:
            printf("invalid choise");
            break;
        }
    }
    printf("\n       * end program *\n");
}
