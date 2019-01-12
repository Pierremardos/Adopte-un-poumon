#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include <winsock.h>
#include <MYSQL/mysql.h>

#include "addPatients_header.h"
#include "zerogets.h"

#include "addLungs_fonctions.h"


void  impossible_change_file(GtkWidget * mainWindow)
{
    GtkWidget * dialog;

dialog = gtk_message_dialog_new (mainWindow,
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "Impossible d'ouvrir le fichier de configuration "
                                 );
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}

void  impossible_open_file(GtkWidget * mainWindow)
{
    GtkWidget * dialog;

dialog = gtk_message_dialog_new (mainWindow,
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "Impossible d'ouvrir le fichier de configuration "
                                 );
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}


void display_error_message(GtkWidget * second_window,GtkWidget * main_box)
{
    GtkWidget * error;

    /* Création de la boite de message */
    /* Type : Information -> GTK_MESSAGE_INFO */
    /* Bouton : 1 OK -> GTK_BUTTONS_OK */
    error = gtk_message_dialog_new (GTK_WINDOW(second_window),
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_ERROR,
                                    GTK_BUTTONS_OK,
                                    "Vous avez saisie un mauvais login/password, veuillez reessayer : ");

    /* Affichage de la boite de message */
    gtk_dialog_run(GTK_DIALOG(error));


    /* Destruction de la boite de message */
    gtk_widget_destroy(error);
}
