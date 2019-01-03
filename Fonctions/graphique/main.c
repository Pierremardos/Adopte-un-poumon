#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#define EXEMPLE_1 0
#define EXEMPLE_2 1
#define EXEMPLE_3 2
#include "fonction.h"



int main(int argc, char **argv)
{
    /* Variables */
    GtkWidget * MainWindow = NULL;
    GtkWidget* mainLabel =NULL;
    gchar* convert_mainLabel =NULL;
    gchar * positionLabel ="GTK_JUSTIFY_RIGHT";

    // Affichage de la fenetre principal


    firstWindow(MainWindow,argc,argv,mainLabel,convert_mainLabel,positionLabel);



    /* On quitte.. */
    return EXIT_SUCCESS;

}


