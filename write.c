void write(int value, char book_title[], char auther_writer[], char gener_type[], int year_a){
FILE *f=fopen("pop.csv","a+");
if(f==NULL)
    printf("file not found");
else{
     fprintf(f,"%d,%s,%s,%s,%d,%d,%f\n",value,book_title,auther_writer,gener_type,year_a,num,pric);
    fclose(f)
}
}
