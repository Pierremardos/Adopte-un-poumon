#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include <winsock.h>
#include <MYSQL/mysql.h>

#include "addPatients_header.h"
#include "zerogets.h"

#include "addLungs_fonctions.h"



void formLungs(GtkWidget * addLungsWindow,GtkWidget * main_box)
{
    int i,j=0;
    GtkWidget * frame;
    GtkWidget * last_name;
    GtkWidget * first_name;
    GtkWidget * sex;
    GtkWidget * old;
    GtkWidget * blood_type;
    GtkWidget * height;
    GtkWidget * weight;
    GtkWidget * hla;
    GtkWidget * plasmapherese;
    GtkWidget * smoke;
    GtkWidget * enter_bloc;
    GtkWidget * clamping;
    GtkWidget * notes;






     }
    /* Creation du premier GtkFrame */
    frame = gtk_frame_new("Ajout d'un poumon");
    gtk_box_pack_start(GTK_BOX(main_box), frame, TRUE, FALSE, 0);



    /* Creation et insertion des elements contenus dans le premier GtkFrame */


    // button_addPatient(addPatientWindow, main_box, name, surname, birth, dateInscription, height, weight,bloodType, HLA, plasmapherese, smoke);

}

void addLungsWindow(int argc, char ** argv,GtkWidget * mainWindow)
{
    GtkWidget * main_box = NULL;
    GtkWidget * LungAddWindow=NULL;

    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);

    /* Cr�ation de la fen�tre */
    LungAddWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(LungAddWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle �v�nementielle */
    gtk_widget_show(LungAddWindow);

    /* On definit le titre de la fen�tre */
    gtk_window_set_title(GTK_WINDOW(LungAddWindow), "Ajout d'un poumon");

    /* D�finition de la position */
    gtk_window_set_position(GTK_WINDOW(LungAddWindow), GTK_WIN_POS_CENTER_ALWAYS  );

    /* D�finition d'un icone de la fen�tre */
    gtk_window_set_icon_from_file(GTK_WINDOW(LungAddWindow),"organes.jpg",NULL);

    /* On d�finit la taile de la fen�tre par d�fault */
    gtk_window_resize(GTK_WINDOW(LungAddWindow), 500,500);

    /* Maximiser la fen�tre */
    gtk_window_maximize (GTK_WINDOW(LungAddWindow));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(LungAddWindow));

    /* Cr�ation de la GtkBox verticale */
    main_box = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(LungAddWindow), main_box);
    formLungs(LungAddWindow,main_box);

    gtk_widget_show_all(LungAddWindow);
    gtk_main();


}


