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
