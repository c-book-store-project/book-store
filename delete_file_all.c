void delallfile(void){
FILE *f2=fopen("popcp.csv","a");
fclose(f2);
remove("pop.csv");
rename("popcp.csv","pop.csv");
}
