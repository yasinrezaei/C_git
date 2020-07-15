#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>


//تابع مقایسه دو فایل و مشخص کردن لاین های متفاوت
void compareFiles(char filename[]) { 

     FILE *main_file, *main_file_copy,*increment;
     main_file=fopen(filename,"r");
    main_file_copy=fopen("Git\\main_file_copy.txt","r");
     increment=fopen("Git\\increment.txt","w");
    int line = 1; 
     char l1[100],l2[100];

    // char ch1 = getc(main_file); 
    // char ch2 = getc(main_file_copy); 
  
    // // error keeps track of number of errors 
    // // pos keeps track of position of errors 
    // // line keeps track of error line 
    // int error = 0, pos = 0, line = 1; 
  
    // // iterate loop till end of file 
    // while (ch1 != EOF && ch2 != EOF) 
    // { 
    //     pos++; 
  
    //     // if both variable encounters new 
    //     // line then line variable is incremented 
    //     // and pos variable is set to 0 
    //     if (ch1 == '\n' && ch2 == '\n') 
    //     { 
    //         line++; 
    //         pos = 0; 
    //     } 
  
    //     // if fetched data is not equal then 
    //     // error is incremented 
    //     if (ch1 != ch2) 
    //     { 
    //         error++; 
    //         printf("Line Number : %d \tError"
    //            " Position : %d \n", line, pos); 
    //     } 
  
    //     // fetching character until end of file 
    //     ch1 = getc(main_file); 
    //     ch2 = getc(main_file_copy); 
    // }


     while (fgets(l1,100,main_file) && fgets(l2,100,main_file_copy)) 
     { 
         
         if(strcmp(l1,l2)) {
             //fputs("sdhf",increment);
            printf("error line %d\n",line);
         }
         line++;
     } 
  

}

// int main() 
// { 
//     // opening both file in read only mode 
//     FILE *fp1 = fopen("f1.txt", "r"); 
//     FILE *fp2 = fopen("f2.txt", "r"); 
  
//     if (fp1 == NULL || fp2 == NULL) 
//     { 
//        printf("Error : Files not open"); 
//        exit(0); 
//     } 
  
//     compareFiles(fp1, fp2); 
  
//     // closing both file 
//     fclose(fp1); 
//     fclose(fp2); 
//     return 0; 
// }
////////////////////////////
//تابع چاپ منو
void printmenu(){
    printf("-------------------menu----------------\n");
    printf("git init ---> 0\n");
    printf("git select---> 1\n");
    printf("git add . ---> 2\n");
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

//ساخت کپی از فایل اصلی
void create_copy(char filename[]){
    char ch;
   FILE *source, *target;
  
   source = fopen(filename, "r");
   target = fopen("Git\\main_file_copy.txt", "w");
 
   while( ( ch = fgetc(source) ) != EOF ){
       fputc(ch, target);
   }
      
   fclose(source);
   fclose(target);
}     
        
