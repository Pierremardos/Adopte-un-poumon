#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "config_files.h"
#include "Graphical_header.h"

void changes_files(GtkWidget * mainWindow, config * configStruct)
{

    char line [100]; // Maximum de caractere sur une line

    string find_equal, width, height, nouveauPatient, nouveauPoumon, pathImage, pathImage2;
    int actual_carac = 0, cursor=0, counter=0, i=0, size=0,intWidth,intHeight;




    FILE* open_file;
    open_file = fopen("config/config.txt","r+");



    if (open_file !=NULL)
    {
        find_equal = malloc(sizeof(char)* 100);
        nouveauPatient = malloc(sizeof(char)* 100);
        nouveauPoumon = malloc(sizeof(char)* 100);
        pathImage = malloc(sizeof(char)* 100);
        pathImage2 = malloc(sizeof(char)* 100);

        width = malloc(sizeof(char)* 100);
        height = malloc(sizeof(char)* 100);


        while ( fgets ( line, sizeof(line), open_file ) != NULL ) // LIS LE FICHIER LIGNE PAR LIGNE
            // Passe a la ligne
        {

            cursor = ftell(open_file);

            find_equal = strstr(line,"=")+1;
            counter++;

            switch(counter)
            {
            case 1 :
                strcpy(width, find_equal);
                intWidth =  atoi(width);
                break;
            case 2 :
                strcpy(height, find_equal);
                intHeight = atoi(height);
                break;
            case 3 :
                strcpy(nouveauPatient, find_equal);
                break;
            case 4 :
                strcpy(nouveauPoumon, find_equal);
                break;
            case 5 :
                strcpy(pathImage, find_equal);
                break;
            case 6 :
                strcpy(pathImage2, find_equal);
                break;
            default:
                impossible_change_file(mainWindow);
                break;
            }




        }

        addConfigStruct(configStruct, intWidth, intHeight, nouveauPatient, nouveauPoumon, pathImage, pathImage2);
        free(pathImage);
        free(pathImage2);
        free(find_equal);
        free(nouveauPatient);
        free(nouveauPoumon);
        free(width);
        free(height);

        fclose( open_file );

    }
    else
    {
        impossible_open_file(mainWindow);
    }
}

void addConfigStruct(config * configStruct,int width, int height, string nouveauPatient, string nouveauPoumon, string pathImage, string pathImage2)
{
    configStruct->width = width;
    configStruct->height = height;
    configStruct->nouveauPatient = nouveauPatient;
    configStruct->nouveauPoumon = nouveauPoumon;
    configStruct->pathImage = pathImage;
    configStruct->pathImage2 = pathImage2;
}
