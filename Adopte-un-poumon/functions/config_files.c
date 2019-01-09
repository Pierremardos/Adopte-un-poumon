#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "config_files.h"
void changes_files(GtkWidget * mainWindow)
{
    char line [50]; // Maximum de caractere sur une line
    char * array;
    int theCurrentChar;
    int cursor=0;
    FILE* open_file;
    int size=0;
    open_file = fopen("config/config.txt","r+");
    if (open_file !=NULL)
    {
        /*
        fseek(open_file,0,SEEK_END);
        size =ftell(open_file);
        printf("%d \n",size);
        fseek(open_file,0,SEEK_SET);
        array = malloc(sizeof(char)*size);

        // LECTURE DU CHEMIN DE L'IMAGE
        fseek(open_file,12,SEEK_SET);

        fread(array,sizeof(char),size/sizeof(char),open_file);
        */
        cursor= ftell(open_file);
        while ( fgets ( line, sizeof(line), open_file ) != NULL ) // LIS LE FICHIER LIGNE PAR LIGNE
            // RAJOUTE /n et /O a la fin de chaque ligne sauf la derniere
        {
            if (strstr(line,"=") != NULL)
            {
                printf("Ok");
            }
            printf("Ligne : %s", line);



        }
        fclose( open_file );
    }
    else
    {
        impossible_open_file(mainWindow);
    }
}


