#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "config_files.h"
void changes_files(GtkWidget * mainWindow)
{
    char * array;
    FILE* open_file;
    int size=0;
    open_file = fopen("config/config.txt","r+");
    if (open_file !=NULL)
    {
        fseek(open_file,0,SEEK_END);
        size =ftell(open_file);
        printf("%d \n",size);
        fseek(open_file,0,SEEK_SET);
        array = malloc(sizeof(char)*size);
        fread(array,sizeof(char),50,open_file);
        puts(array);


    }
    else
    {
       impossible_open_file(mainWindow);
    }
}
