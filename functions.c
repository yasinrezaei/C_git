#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
//ساخت کپی از فایل اصلی

void create_copy(char filename[],char directory[]){
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
//تابع حذف کردم اسم فایل از فایل های سلکت شده
void remove_select(int unselect_id){
    int counter=0;
    FILE* Select=fopen("Git\\select.txt","r");
    FILE* new_Select=fopen("Git\\new_select.txt","a");
    char line[100];
    char c[10];
    char select_array[100][100];
    itoa(unselect_id,c,10);
    while (fgets(line,100,Select))
    {
        if(line[0]-'0'!=unselect_id){
           
             
             //fseek(new_Select,-1,SEEK_END);
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
    create_copy("Git\\new_select.txt","Git\\select.txt");
    create_copy("Git\\free.txt","Git\\new_select.txt");    
}



//چاپ کردن فایل سلکت
void write_selected_file(){
    FILE* Select=fopen("Git\\select.txt","r");
    char line[100];
    printf("----selected files----\n");
    while (fgets(line,100,Select))
    {
        printf("%s\n",line);
    }
    printf("-----------------------\n");
    
}

//تابع اضافه کردن اسم فایل ها
void select(char filename[],int select_id){

    FILE* Select=fopen("Git\\select.txt","a");

    //printf("id =%d\n",select_id);
    fseek(Select,-1,SEEK_END);
    fprintf(Select,"%d ) %s\n",select_id,filename);
    fclose(Select);
}



//تابع مقایسه دو فایل و مشخص کردن لاین های متفاوت
void compareFiles(char filename[]) { 

    FILE *main_file, *main_file_copy,*increment;
    main_file=fopen(filename,"r");
    main_file_copy=fopen("Git\\main_file_copy.txt","r");
    increment=fopen("Git\\increment.txt","w");
    int line = 1; 
    char l1[100],l2[100];
     while (fgets(l1,100,main_file) && fgets(l2,100,main_file_copy)) 
     { 
         
         if(strcmp(l1,l2)) {
            fprintf(increment,"+line %d  %s",line,l1);
         }
         line++;
     } 
     fclose(main_file);
     fclose(main_file_copy);
     fclose(increment);
}

//تابع چاپ منو

void printmenu(){
    printf("-------------------menu----------------\n");
    printf("git init ---> 0\n");
    printf("git select---> 1\n");
    printf("git unselect---> 2\n");
    printf("git add . ---> 3\n");
    printf("exit ----> 5\n");
    printf("---------------------------------------\n");
}

///تابع وجود فایل در صفحه اصلی

int file_exist(char filename[]){
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
}

     
        
