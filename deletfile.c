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
