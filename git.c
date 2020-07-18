#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"headerfile.h"

/**
 * Most functions are written in another file and are only called here by include header file
 */

int main(){

    char filename[100];
    int select_id=0;
    int commit_id=0;
    int unselect_id;
    char commit[100];
    char s[10];
    
    /**
    * in this loop we can see menu and selcect your command.
    */
    while (1)
    {
        printMenu();
        char opt;
        int id,reset_id,stash_id,last_id;
        char dir[100]="Git\\commit\\";
        char line[100];
        /**
         * this strings @param s1 @param s2 @param s3 @param s4 @param s5 @param s6 using for concatinate string to build suitble command for system function.
         */
        char s1[100];
        char s2[100];
        char s3[100];
        char s4[100];
        char s5[10];
        printf(YEL"Command:"RESET);
        scanf("%c",&opt);
        system("cls");
        /**
        *switch case Used to specify the processes that must be performed after a command
        */
        switch (opt)
        {
        case '0':
            system("cls");
            if (mkdir("Git")) {
                printf("------------------------------\n");
                printf(RED"'Git' file already made !\n"RESET);
                printf("------------------------------\n");
            }
                
            else { 
                printf("------------------------------\n");
                printf(GRN"git initialized !\n"RESET);
                printf("------------------------------\n");
                system("pause");
                system("cls");
                break; 
            }
            system("pause");
            system("cls");
            break;
        case '1':
            if(!fileExist("Git")){
                printf("------------------------------\n");
                printf(RED"please initial git in this folder and then select your file!\n"RESET);
                printf("------------------------------\n");
                system("pause");
                system("cls");
                break;
            }
            if(select_id!=0){
                writeSelectedFile();
            }
            else{
                printf(RED"------------------------------\n"RESET);
                printf(RED"No file selected !\n"RESET);
                printf(RED"------------------------------\n"RESET);
            }
            
            printf("Enter filename to select : ");
            scanf("%s",filename);
            
            if(fileExist(filename)){
                printf(GRN"------------------------------\n"RESET);
                printf(GRN"'%s' selected!\n"RESET,filename);
                printf(GRN"------------------------------\n"RESET);
                system("pause");
                system("cls");
                select_id++;
                select(filename,select_id);
            }
            else {
                printf("file ' %s ' does not exist!\n",filename);
                system("pause");
                system("cls");
            }
                
            break;
        case '2':
            getchar();
            if(select_id!=0) writeSelectedFile();
            else  printf(RED"No file selected !\n"RESET); 
            printf("enter file id:");
            scanf("%d",&unselect_id);
            if(unselect_id<=select_id) {
                removeSelect(unselect_id);
                select_id--;
            }
            else printf(RED"this file didnot select !\n"RESET);
            system("pause");
            system("cls");
            break;
        case '*':
            printf("select all \n");
            system("pause");
            system("cls");
            break;
        case '#':
            unselectAll();
            system("pause");
            system("cls");
            break;
        case '3':
            mkdir("Git\\commit");
            FILE* commits_name=fopen("Git\\commit\\commits_name.txt","a");
            printf("commit message : ");
            scanf("%s",commit);
            fputs(commit,commits_name);
            fputs("\n",commits_name);
            commit_id++;
            itoa(commit_id,s,10);
            
            strcat(dir,s);
            mkdir(dir);
            printf("------------------------------\n");
            printf(RED"commit '%s' save!\n"RESET,commit);
            printf("------------------------------\n");
            system("pause");
            system("cls");
            FILE* in_select=fopen("Git\\select.txt","r");
            while (fgets(line,100,in_select)){
                sscanf(line,"%d %s",&id,filename);
                strcpy(s1,"copy ");
                strcpy(s2,filename);
                strcpy(s3," Git\\commit\\");
                itoa(commit_id,s5,10);
                strcpy(s4,s5);
                strcat(s1,s2);
                strcat(s1,s3);
                strcat(s1,s4);
                system(s1);
                }
            fclose(commits_name);
            system("cls");
            break;

        case '4':
            Log();
            system("pause");
            system("cls");
            break;

        case '5':
            printf("enter the id of commit:");
            scanf("%d",&reset_id);
            Reset(reset_id);
            break;
        case '6':
            status(commit_id);
            system("pause");
            system("cls");
            break;
        case '7':
            printf("enter the id of commit:");
            scanf("%d",&stash_id);
            Reset(stash_id);
            system("cls");
            break;
        case '8':
            Reset(commit_id);
            printf(RED "Reset to Previous id\n" RESET);
            system("pause");
            system("cls");
            break;

        case '9':
            system("cls"); 
            printf(WHT"\n\n--------------------\n"RESET);
            printf(RED"---END GIT---\n"RESET);
            printf(WHT"--------------------\n"RESET);
            system("pause");
            system("cls");
            exit(0);
        default:
            break;
        }
    }
    return 0;
}