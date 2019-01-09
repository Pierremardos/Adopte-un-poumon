#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock.h>
#include <gtk/gtk.h>
#include <MYSQL/mysql.h>
#include "addPatients_header.h"
#include "zerogets.h"




void addPatientStruct(string name,string surname, string birth, string dateInscription, string height, string weight, string bloodType, string HLA, string plasmapherese, string smoke)
{
    patient p;
    p.name = name;
    p.surname = surname;
    p.birth = birth;
    p.dateInscription = dateInscription;
    p.height = height;
    p.weight = weight;
    p.bloodType = bloodType;
    p.HLA = HLA;
    p.plasmapherese = plasmapherese;
    p.smoke = smoke;



}

string query()
{
    addPatientStruct("jonas", "nizard", "1998-09-07","2019-01-1","175","60","o","","","0");
    patient p;
    char request[600];
    char p1[160]="INSERT INTO patients (name, surname, birth, dateInscription, height, weight, bloodType, HLA, plasmapherese, smoke) VALUES (";
    char comma[2] = ",";
    char p2[2] = ")";
    strcpy(request, p1);
    strcat(request,p.name);
    strcat(request,comma);
    strcat(request,p.surname);
    strcat(request,comma);
    strcat(request,p.birth);
    strcat(request,comma);
    strcat(request,p.dateInscription);
    strcat(request,comma);
    strcat(request,p.height);
    strcat(request,comma);
    strcat(request,p.weight);
    strcat(request,comma);
    strcat(request,p.bloodType);
    strcat(request,comma);
    strcat(request,p.HLA);
    strcat(request,comma);
    strcat(request,p.plasmapherese);
    strcat(request,comma);
    strcat(request,p.smoke);
    return (request);
}
void add(string request)
{
    struct patient p;
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    if(mysql_real_connect(&mysql, "localhost","root", "", "pulmonax", 0, NULL, 0))
    {

        mysql_query(&mysql, query());
        mysql_close(&mysql);
    }
    else
    {
        printf("Erreur connexion");

    }
}
/*----------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------
------------------------------------------Passage Graphique ------------------------------
------------------------------------------------------------------------------------------*/

void addPatientWindow(int argc, char ** argv,GtkWidget * mainWindow)
{
    GtkWidget * main_box = NULL;
    GtkWidget * patientAddWindow=NULL;

    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);

    /* Cr�ation de la fen�tre */
    patientAddWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(patientAddWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle �v�nementielle */
    gtk_widget_show(patientAddWindow);

    /* On definit le titre de la fen�tre */
    gtk_window_set_title(GTK_WINDOW(patientAddWindow), "Ajout d'un patient");

    /* D�finition de la position */
    gtk_window_set_position(GTK_WINDOW(patientAddWindow), GTK_WIN_POS_CENTER_ALWAYS  );

    /* D�finition d'un icone de la fen�tre */
    gtk_window_set_icon_from_file(GTK_WINDOW(patientAddWindow),"organes.jpg",NULL);

    /* On d�finit la taile de la fen�tre par d�fault */
    gtk_window_resize(GTK_WINDOW(patientAddWindow), 500,500);

    /* Maximiser la fen�tre */
    gtk_window_maximize (GTK_WINDOW(patientAddWindow));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(patientAddWindow));

    /* Cr�ation de la GtkBox verticale */
    main_box = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(patientAddWindow), main_box);
    formPatient(patientAddWindow, main_box);

    gtk_widget_show_all(patientAddWindow);
    gtk_main();


}

void formPatient(GtkWidget * SecondWindow,GtkWidget * main_box)
{
    GtkWidget * pFrame;
    GtkWidget * label;
    GtkWidget * name;
    GtkWidget * surname;
    GtkWidget * birth;
    GtkWidget * dateInscription;
    GtkWidget * height;
    GtkWidget * weight;
    GtkWidget * bloodType;
    GtkWidget * HLA;
    GtkWidget * plasmapherese;
    GtkWidget * smoke;



    /* Creation du premier GtkFrame */
    pFrame = gtk_frame_new("Ajout d'un patient");
    gtk_box_pack_start(GTK_BOX(main_box), pFrame, TRUE, FALSE, 0);


    /* Creation et insertion des elements contenus dans le premier GtkFrame */
    label = gtk_label_new("Nom :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    name = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), name, TRUE, TRUE, 0);

    label = gtk_label_new("Prenom :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    surname = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), surname, FALSE, FALSE, 0);

    label = gtk_label_new("Date de naissance (JJ/bloodTypeMM/AAAA) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    birth = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), birth, FALSE, FALSE, 0);

    label = gtk_label_new("Date d'inscription (JJ/MM/AAAA) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    dateInscription = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), dateInscription, FALSE, FALSE, 0);

    label = gtk_label_new("Taille (en cm) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    height = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), height, FALSE, FALSE, 0);

    label = gtk_label_new("Poids (en kg) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    weight = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), weight, FALSE, FALSE, 0);

    label = gtk_label_new("Poids (en kg) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    bloodType = gtk_entry_new_with_max_length(3);
    gtk_box_pack_start(GTK_BOX(main_box), bloodType, FALSE, FALSE, 0);



}
