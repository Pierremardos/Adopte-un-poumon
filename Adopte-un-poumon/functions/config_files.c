#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "config_files.h"
#include "Graphical_header.h"

void changes_files(GtkWidget * mainWindow)
{
    char line [100]; // Maximum de caractere sur une line

    string find_equal, pathImage, width, height;
    int actual_carac = 0, cursor=0, counter=0, i=0, size=0, intWidht=0,intHeight=0;



    FILE* open_file;
    open_file = fopen("config/config.txt","r+");



    if (open_file !=NULL)
    {
        find_equal = malloc(sizeof(char)* 100);
        pathImage = malloc(sizeof(char)* 100);

        width = malloc(sizeof(char)* 100);
        height = malloc(sizeof(char)* 100);


        while ( fgets ( line, sizeof(line), open_file ) != NULL ) // LIS LE FICHIER LIGNE PAR LIGNE
            // Passe a la ligne
        {


            cursor = ftell(open_file);

            find_equal = strstr(line,"=")+1;
            printf("Le curseur est a : %d \n",cursor);
            counter++;

            printf("%d\n",counter);
            puts(find_equal);



            switch(counter)
            {
            case 1 :
                strcpy(pathImage, find_equal);
                puts(pathImage);
                ChangePathImage(pathImage);
                break;
            case 2 :
                strcpy(width, find_equal);
                puts(width);
                intWidht =  atoi(width);
                break;
            case 3 :
                strcpy(height, find_equal);
                puts(height);
                intHeight = atoi(height);
                break;
            default:
                impossible_change_file(mainWindow);
                break;

            }




        }

        free(find_equal);
        free(pathImage);
        free(width);
        free(height);

        fclose( open_file );

    }
    else
    {
        impossible_open_file(mainWindow);
    }
}

string ChangePathImage(string pathImage)
{
    return pathImage;
}

