#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "config_files.h"
#include "Graphical_header.h"

void changes_files(GtkWidget * mainWindow, config * configStruct)
{

    char line [100]; // Maximum de caractere sur une line
<<<<<<< HEAD
    char find_equal[100];
    string width, height, nouveauPatient, nouveauPoumon, pathImage, pathImage2;
=======

    string find_equal2, width, height, nouveauPatient, nouveauPoumon, pathImage, pathImage2;
>>>>>>> c3ae4ceae2af439eaac6813af6ac98ae905b854d
    int actual_carac = 0, cursor=0, counter=0, i=0, size=0,intWidth,intHeight;
    FILE* open_file;
    open_file = fopen("config/config.txt","r+");
    if (open_file !=NULL)
    {
<<<<<<< HEAD
        //find_equal = malloc(sizeof(char)* 1000);
=======
        find_equal2 = malloc(sizeof(char)* 100);
>>>>>>> c3ae4ceae2af439eaac6813af6ac98ae905b854d
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
<<<<<<< HEAD
            //find_equal = strstr(line,"=")+1;
            strcpy(find_equal,strstr(line,"=")+1);
            find_equal[strcspn(find_equal, "\n")] = 0;
            puts(find_equal);
=======
            find_equal2 = strstr(line,"=")+1;
            puts(pathImage2);
>>>>>>> c3ae4ceae2af439eaac6813af6ac98ae905b854d
            counter++;
            switch(counter)
            {
            case 1 :
                strcpy(width, find_equal2);
                intWidth =  atoi(width);
                break;
            case 2 :
                strcpy(height, find_equal2);
                intHeight = atoi(height);
                break;
            case 3 :
                strcpy(nouveauPatient, find_equal2);
                break;
            case 4 :
                strcpy(nouveauPoumon, find_equal2);
                break;
            case 5 :
                strcpy(pathImage, find_equal2);
                break;
            case 6 :
                strcpy(pathImage2, find_equal2);
                break;
            default:
                impossible_change_file(mainWindow);
                break;
            }
        }


        addConfigStruct(configStruct, intWidth, intHeight, nouveauPatient, nouveauPoumon, pathImage, pathImage2);
        free(find_equal2);
        free(pathImage);
        free(pathImage2);
<<<<<<< HEAD
=======

>>>>>>> c3ae4ceae2af439eaac6813af6ac98ae905b854d
        free(nouveauPatient);
        free(nouveauPoumon);
        free(width);
        free(height);
        //free(find_equal);

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
