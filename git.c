#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"headerfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 

int main(){
    char filename[100];
    while (1)
    {
        printmenu();
        int opt;
        scanf("%d",&opt);
        switch (opt)
        {
        case 0:
            system("cls");
            if (!mkdir("Git")) 
                printf("Directory created\n"); 
            else { 
                printf("git initialized !\n"); 
                system("pause");
                system("cls");
                break; 
            }
            system("pause");
            system("cls");
            break;
        case 1:
            if(!file_exist("Git")){
                printf("please initial git in this folder and then select your file\n");
                system("pause");
                system("cls");
                break;
            }
            printf("Enter filename : ");
            scanf("%s",filename);
            if(file_exist(filename)){
                printf("'%s' selected!\n",filename);
                system("pause");
                system("cls");
                create_copy(filename);
            }
            else {
                printf("file ' %s ' does not exist!\n",filename);
                system("pause");
                system("cls");
            }
                
            break;
        case 2:
            
            compareFiles(filename);
        
        default:
            break;
        }
    }
    



    return 0;
}