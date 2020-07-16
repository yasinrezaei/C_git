#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"headerfile.h"


int main(){
    char filename[100];
    int select_id=0;
    int unselect_id;

    while (1)
    {
        printmenu();
        int opt;
        scanf("%d",&opt);
        system("cls");
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
            if(select_id!=0){
                write_selected_file();
            }
            else{
                printf("no file selected !\n");
            }
            
            printf("Enter filename to select : ");
            scanf("%s",filename);
            if(file_exist(filename)){
                printf("'%s' selected!\n",filename);
                system("pause");
                system("cls");
                create_copy(filename,"Git\\main_file_copy.txt");
                select_id++;
                select(filename,select_id);


            }
            else {
                printf("file ' %s ' does not exist!\n",filename);
                system("pause");
                system("cls");
            }
                
            break;
        case 2:
            getchar();
            if(select_id!=0) write_selected_file();
            else printf("no file selected!\n------------\n");
            printf("enter file id:");
            scanf("%d",&unselect_id);
            if(unselect_id<=select_id) {
                remove_select(unselect_id);
                select_id--;
            }
            else printf("this file didnot select !\n");
            
            
            system("pause");
            system("cls");
            break;

        case 3:
            compareFiles(filename);
            break;
            
        case 5:
            system("cls");
            printf("finish\n");
            system("pause");
            exit(0);
        default:
            break;
        }
    }
    



    return 0;
}