#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "config_files.h"
void changes_files(GtkWidget * mainWindow)
{
    char line [50]; // Maximum de caractere sur une line
    char * array;
    char * find_equal;
    char * pathimage;
    char * sizeWindow;
    char * test;
    int actual_carac = 0;
    int cursor=0;
    int counter=0;
    int i=0;
    FILE* open_file;
    int size=0;
    open_file = fopen("config/config.txt","r+");
    if (open_file !=NULL)
    {
        find_equal = malloc(sizeof(char)* 50);
        pathimage = malloc(sizeof(char)* 50);
        sizeWindow = malloc(sizeof(char)* 50);
        test = malloc(sizeof(char)* 50);



        while ( fgets ( line, sizeof(line), open_file ) != NULL ) // LIS LE FICHIER LIGNE PAR LIGNE
            // RAJOUTE /n et /O a la fin de chaque ligne sauf la derniere
        {

            fseek(open_file,0,SEEK_CUR);
            cursor = ftell(open_file);
            // printf("%d",cursor);
            find_equal = strstr(line,"=")+1;


            sscanf( find_equal, "%s %s %s", pathimage, sizeWindow,test );
            //puts(pathimage);
            sscanf(pathimage,"%s %s %s",pathimage,sizeWindow,test);
            puts(sizeWindow);



        }

        fclose( open_file );
        free(find_equal);
    }
    else
    {
        impossible_open_file(mainWindow);
    }
}


