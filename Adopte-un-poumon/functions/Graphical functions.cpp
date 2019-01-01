#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#define EXEMPLE_1 0
#define EXEMPLE_2 1
#define EXEMPLE_3 2
#include "fonction.h"

void validate_connexion()
{

}
void button_connexion(GtkWidget * second_window,GtkWidget * main_box,gint iExemple,GtkWidget *login,GtkWidget *password)
{
    GtkWidget *pQuitBtn;
    switch(iExemple)
    {
    default:
    case EXEMPLE_1:
        /* Bouton avec un label */
        pQuitBtn = gtk_button_new_with_label(" Try to connect ! ");
        break;

    }
    /* Connexion du signal "clicked" du bouton */
    g_signal_connect_swapped(G_OBJECT(pQuitBtn), "clicked", G_CALLBACK(validate_connexion), NULL);

    gtk_box_pack_start (GTK_BOX (main_box), pQuitBtn, FALSE, FALSE, 0);


}

void connexion(GtkWidget * SecondWindow,GtkWidget * main_box)
{
    GtkWidget *login;
    GtkWidget *pFrame;
    GtkWidget * label;
    GtkWidget * password;
    /* Creation du premier GtkFrame */
    pFrame = gtk_frame_new("Connexion");
    gtk_box_pack_start(GTK_BOX(main_box), pFrame, TRUE, FALSE, 0);



    /* Creation et insertion des elements contenus dans le premier GtkFrame */
    label = gtk_label_new("Login :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    login = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), login, TRUE, FALSE, 0);


    label = gtk_label_new("Password :");
    gtk_box_pack_start(GTK_BOX(main_box), label, TRUE, FALSE, 0);
    /* Creation du GtkEntry avec 8 caracteres maximum */
    password = gtk_entry_new_with_max_length(8);

     /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(password), '*');
    /* Insertion du GtkEntry dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(main_box), password, TRUE, FALSE, 0);

        button_connexion(SecondWindow,main_box,EXEMPLE_3,login,password);

}


void delete_main_window(int argc,char **argv,GtkWidget * mainWindow)
{
    gtk_widget_destroy(mainWindow);

}

void second_window(int argc, char ** argv,GtkWidget * mainWindow)
{
    GtkWidget * main_box = NULL;
    GtkWidget * SecondWindow=NULL;

    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);

    /* Cr�ation de la fen�tre */
    SecondWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(SecondWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle �v�nementielle */
    gtk_widget_show(SecondWindow);

    /* On definit le titre de la fen�tre */
    gtk_window_set_title(GTK_WINDOW(SecondWindow), "Configuration du programme :");

    /* D�finition de la position */
    gtk_window_set_position(GTK_WINDOW(SecondWindow), GTK_WIN_POS_CENTER_ALWAYS  );

    /* D�finition d'un icone de la fen�tre */
    gtk_window_set_icon_from_file(GTK_WINDOW(SecondWindow),"organes.jpg",NULL);

    /* On d�finit la taile de la fen�tre par d�fault */
    gtk_window_resize(GTK_WINDOW(SecondWindow), 500,500);

    /* Maximiser la fen�tre */
    gtk_window_maximize (GTK_WINDOW(SecondWindow));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(SecondWindow));

    /* Cr�ation de la GtkBox verticale */
    main_box = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(SecondWindow), main_box);
    connexion(SecondWindow,main_box);

    gtk_widget_show_all(SecondWindow);
    gtk_main();


}
void first_image(GtkWidget * mainWindow,GtkWidget * main_box,gchar * path_image)
{
    GtkWidget * image;

    /* Chargement d'une image a partir d'un fichier */
    image = gtk_image_new_from_file(path_image);
    gtk_box_pack_start(GTK_BOX(main_box), image, TRUE, FALSE, 1);

}

void launch_program(GtkWidget * mainWindow,GtkWidget * main_box, gint iExemple)
{
    GtkWidget *pQuitBtn;
    switch(iExemple)
    {
    default:
    case EXEMPLE_1:
        /* Bouton avec un label */
        pQuitBtn = gtk_button_new_with_label("Lancer le programme");
        break;

    }
    /* Connexion du signal "clicked" du bouton */
    g_signal_connect_swapped(G_OBJECT(pQuitBtn), "clicked", G_CALLBACK(second_window), NULL);

    gtk_box_pack_start (GTK_BOX (main_box), pQuitBtn, FALSE, FALSE, 0);


}
/*
int Hla(char  hla_test[3])
{
    if (strcmp(hla_test,"A2") == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
*/

char * convert_text (gchar * text)
{
    text= g_locale_to_utf8(text, -1, NULL, NULL, NULL);
    return text;
}

void creation_label (GtkWidget * MainWindow,GtkWidget* mainLabel,gchar* convert_mainLabel,gchar * positionLabel, GtkWidget * main_box)
{
    convert_mainLabel = convert_text("ADOPTE UN POUMON \n --------------------------- \n --------------------------- \n       Software by Arthur & Jonas \n --------------------------- \n ");
    mainLabel=gtk_label_new(convert_mainLabel); // Application de la convertion � notre label
    g_free(convert_mainLabel); // Lib�ration de la m�moire

    gtk_label_set_use_markup(GTK_LABEL(mainLabel), TRUE); // On dit que l'on utilise les balises pango

    gtk_label_set_justify(GTK_LABEL(mainLabel), GTK_JUSTIFY_CENTER); // On centre notre texte

    // gtk_container_add(GTK_CONTAINER(MainWindow),mainLabel);  // On ajoute le label a l'interieur de 'Fenetre'

    gtk_box_pack_start (GTK_BOX (main_box), mainLabel, FALSE, FALSE, 0);


    gtk_widget_show_all(MainWindow); // On affiche 'Fenetre' et tout ce qu'il contient

    g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
}


void firstWindow (GtkWidget * MainWindow,int argc, char **argv,GtkWidget* mainLabel,gchar* convert_mainLabel,gchar * positionLabel)
{
    GtkWidget * main_box = NULL;
    gchar * path_image ="./esgi.png";
    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);

    /* Cr�ation de la fen�tre */
    MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle �v�nementielle */
    gtk_widget_show(MainWindow);

    /* On definit le titre de la fen�tre */
    gtk_window_set_title(GTK_WINDOW(MainWindow), "Gestion de transplantation d'organes");

    /* D�finition de la position */
    gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER_ALWAYS  );

    /* D�finition d'un icone de la fen�tre */
    gtk_window_set_icon_from_file(GTK_WINDOW(MainWindow),"test.png",NULL);

    /* On d�finit la taile de la fen�tre par d�fault */
    gtk_window_resize(GTK_WINDOW(MainWindow), 800,800);

    /* Maximiser la fen�tre */
    gtk_window_maximize (GTK_WINDOW(MainWindow));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(MainWindow));

    /* Cr�ation de la GtkBox verticale */
    main_box = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(MainWindow), main_box);


    // CREATION DU PREMIER LABEL DE LA FENETRE
    creation_label(MainWindow,mainLabel,convert_mainLabel,positionLabel,main_box);


    first_image(MainWindow,main_box,path_image);

    launch_program(MainWindow,main_box,EXEMPLE_3);


    gtk_widget_show_all(MainWindow);
    gtk_main();
}
