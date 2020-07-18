#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
/** 
 * define for colors in print
 */

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"


/**
 
 * This function using for check the file exist or no.
 * @param filename[] for search in files.
 */

int fileExist(char filename[]){
    DIR *d;
    int counter=0;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL){
            if(counter>=1){
                if(!strcmp(dir->d_name,filename)){
                    return 1;
                }
            }
            counter++;
            }
        closedir(d);
    }
    return 0;
}



int compareFiles(s1, s2) 
{ 
    FILE* fp1=fopen(s1,"r");
    FILE* fp2=fopen(s2,"r"); 
    char ch1 = getc(fp1); 
    char ch2 = getc(fp2); 

    int line = 1; 
  
    // iterate loop till end of file 
    while (ch1 != EOF && ch2 != EOF) 
    { 
        if (ch1 != ch2) 
        { 
            return 0;
        } 
        ch1 = getc(fp1); 
        ch2 = getc(fp2); 
    } 
  
    return 1;
} 


/////////////////////////
void status(int commit_id){
    printf(GRN"----deleted files----\n"RESET);
        FILE *del_select=fopen("Git\\select.txt","r");
        char l[100];
        int i;
        char s[100];
        while (fgets(l,100,del_select))
        {
            sscanf(l,"%d %s",&i,s);
            if(fileExist(s)==0){
                printf("%s\n",s);
            }
        }
        
    ///////////////////////
    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100];
    char s5[10];
    char line[100];
    printf(GRN"----selected files----\n"RESET);
    FILE* s_select=fopen("Git\\select.txt","r");
    while (fgets(line,100,s_select))
    {
        int id;
        char s[100];
        sscanf(line,"%d %s",&id,s);
        printf("%d) %s\n",id,s);
    }
    printf(GRN"----Modified files----\n"RESET);
    DIR *d;
    int counter=0;
    struct dirent *dir;
    for(int i=1;i<=commit_id;i++){
        strcpy(s1,"Git\\commit\\");
        itoa(i,s5,10);
        strcat(s1,s5);
        d = opendir(s1);
        if (d) {
            while ((dir = readdir(d)) != NULL){
                strcpy(s2,"Git\\commit\\");
                strcat(s2,s5);
                strcat(s2,dir->d_name);
                if(counter>=1){
                    strcpy(s3,dir->d_name);
                    printf("%s\n",s1);
                    printf("%s\n",s2);
                    if(!compareFiles(s2,s3)){
                        printf("%s\n",dir->d_name);
                    }
                }
                counter++;
                }
            closedir(d);
        }
        /////////////////
        

    }
    printf(GRN"----------------------\n"RESET);
   
    
}
/** 
 * This function using for reset files by get commit id.
 * 
 * @param reset_id id of file to be deleted
 */
void Reset(int reset_id){
    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100];
    char s5[10];
    DIR *d;
    int counter=0;
    struct dirent *dir;
    strcpy(s1,"Git\\commit\\");
    itoa(reset_id,s5,10);
    strcat(s1,s5);
    d = opendir(s1);
    if (d) {
        while ((dir = readdir(d)) != NULL){

            if(counter>=2){
                strcpy(s2,"copy Git\\commit\\");
                strcat(s2,s5);
                strcat(s2,"\\");
                strcat(s2,dir->d_name);
                strcat(s2," ");
                strcat(s2,dir->d_name);
                system(s2);   
            }
            counter++;
            }
        closedir(d);
        system("cls");
    }
}

void Log(){
    char line[100];
    int i=1;
    FILE* Commits=fopen("Git\\commit\\commits_name.txt","r");
    printf("----commits----\n");
    printf("---------------\n");
    while (fgets(line,100,Commits)){
        printf(GRN"id = %d message = '%s'\n"RESET,i,line);
        i++;
    }
    printf("---------------\n");
    printf("---------------\n");
}


/** 
 * This function using for create copy of files.
 * 
 * @param filename[] source files directory
 * @param directory[] target files directory
 */

void createCopy(char filename[],char directory[]){
   char ch;
   FILE *source, *target;
  
   source = fopen(filename, "r");
   target = fopen(directory, "w");
 
   while( ( ch = fgetc(source) ) != EOF ){
       fputc(ch, target);
   }  
   fclose(source);
   fclose(target);
}

/** 
 * This function using for delete unselected file.
 * 
 * @param nselect_id id of unselected file.
 */

void removeSelect(int unselect_id){
    int counter=0;
    FILE* Select=fopen("Git\\select.txt","r");
    FILE* new_Select=fopen("Git\\new_select.txt","a");
    char line[100];
    char c[10];
    itoa(unselect_id,c,10);
    while (fgets(line,100,Select))
    {
        if(line[0]-'0'!=unselect_id){
             if(line[0]-'0'<unselect_id){
                 fprintf(new_Select,"%s\n",line);
                }
            else{
                 int a=line[0]-'0';
                 a--;
                 itoa(a,c,10);
                 line[0]=c[0];
                fprintf(new_Select,"%s",line);
            }
        }
    }
    fclose(new_Select);
    createCopy("Git\\new_select.txt","Git\\select.txt");
    createCopy("Git\\free.txt","Git\\new_select.txt");    
}

/** 
 * This function using for print selected file.
 */

void writeSelectedFile(){
    FILE* Select=fopen("Git\\select.txt","r");
    char line[100];
    printf(BLU"----selected files----\n"RESET);
    printf(BLU"----------------------\n"RESET);
    while (fgets(line,100,Select))
    {
        printf("%s\n",line);
    }
    printf(BLU"----------------------\n"RESET);
    printf(BLU"----------------------\n"RESET);
    
}

/** 
 * This function using for add filename to selected files.
 * @param filename[] selected files name.
 * @param select_id id of selected file.
 */

void select(char filename[],int select_id){

    FILE* Select=fopen("Git\\select.txt","a");
    fseek(Select,-1,SEEK_END);
    fprintf(Select,"%d %s\n",select_id,filename);
    fclose(Select);
}



void printMenu(){
    printf(BLU"-----------menu----------\n"RESET);
    printf(BLU"|"RESET);
    printf("    git init     0      ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git select   1(*)   ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git unselect 2(#)   ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git commit   3      ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git log      4      ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git reset    5      ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git status   6      ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git stash    7      ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    git stashpop 8      ");
    printf(BLU"|\n"RESET);
    printf(BLU"|"RESET);
    printf("    exit         9      ");
    printf(BLU"|\n"RESET);
    printf(BLU"--------------------------\n"RESET);
}



     
        
