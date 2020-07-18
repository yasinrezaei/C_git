#include"functions.c"
void printmenu();
int file_exist(char filename[]);
void write_selected_file();
void createCopy(char filename[],char directory[]);
void select(char filename[],int select_id);
void Log();
void removeSelect(int unselect_id);