#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "config_files.h"
#include "Graphical_header.h"

void changes_files(GtkWidget * mainWindow)
{
    char line [100]; // Maximum de caractere sur une line
    string array;
    string find_equal;
    string pathimage;
    string sizeWindow;
    string test;
    int actual_carac = 0, cursor=0, counter=0, i=0, size=0;



    FILE* open_file;
    open_file = fopen("config/config.txt","r+");



    if (open_file !=NULL)
    {
        find_equal = malloc(sizeof(char)* 100);
        pathimage = malloc(sizeof(char)* 100);
        sizeWindow = malloc(sizeof(char)* 100);
        test = malloc(sizeof(char)* 100);



        while ( fgets ( line, sizeof(line), open_file ) != NULL ) // LIS LE FICHIER LIGNE PAR LIGNE
            // Passe a la ligne
        {


            cursor = ftell(open_file);

            find_equal = strstr(line,"=")+1;

            counter++;

            printf("%d\n",counter);
            puts(find_equal);



            switch(counter)
            {
            case 1 :
                pathimage = find_equal;
                puts(pathimage);
                break;
            case 2 :
                test = find_equal;
                puts(test);
                break;
            case 3 :
                sizeWindow = find_equal;
                puts(sizeWindow);
                break;
            default:
                impossible_change_file(mainWindow);

            }
        puts(pathimage);

        }


        fclose( open_file );
        free(find_equal);
        free(pathimage);
        free(sizeWindow);
        free(test);
    }
    else
    {
        impossible_open_file(mainWindow);
    }
}


