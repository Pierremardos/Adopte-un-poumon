#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include <winsock.h>
#include <MYSQL/mysql.h>

#include "addPatients_header.h"
#include "zerogets.h"

#include "addLungs_fonctions.h"


void addLungsStruct(lung * lung_comparate,string last_name,string first_name, string sex, string old,string blood_type, string height, string weight, string hla, string plasmapherese, string smoke,string enter_bloc,string clamping,string notes)
{
    lung_comparate->last_name = last_name;
    lung_comparate->first_name = first_name;
    lung_comparate->sex = sex;
    lung_comparate->old = old;
    lung_comparate->blood_type = blood_type;
    lung_comparate->height = height;
    lung_comparate->weight = weight;
    lung_comparate->hla = hla;
    lung_comparate->plasmapherese = plasmapherese;
    lung_comparate->smoke = smoke;
    lung_comparate->enter_bloc = enter_bloc;
    lung_comparate->clamping = clamping;
    lung_comparate->notes = notes;
}

void validate_addLungs(GtkWidget *button_co,GtkWidget * addLungsWindow,GtkWidget * main_box,int argc,char **argv)
{

    GtkEntry * last_name_;
    GtkEntry * first_name_;
    GtkEntry * sex_;
    GtkEntry * old_;
    GtkEntry * blood_type_;
    GtkEntry * height_;
    GtkEntry * weight_;
    GtkEntry * hla_;
    GtkEntry * plasmapherese_;
    GtkEntry * smoke_;
    GtkEntry * enter_bloc_;
    GtkEntry * clamping_;
    GtkEntry * notes_;

    const gchar * last_name;
    const gchar * first_name;
    const gchar * sex;
    const gchar * old;
    const gchar * blood_type;
    const gchar * height;
    const gchar * weight;
    const gchar * hla;
    const gchar * plasmapherese;
    const gchar * smoke;
    const gchar * enter_bloc;
    const gchar * clamping;
    const gchar * notes;
    string request;


    last_name_ = g_object_get_data (G_OBJECT(button_co), "last_name");
    first_name_ = g_object_get_data (G_OBJECT(button_co), "first_name");
    sex_ = g_object_get_data (G_OBJECT(button_co), "sex");
    old_ = g_object_get_data (G_OBJECT(button_co), "old");
    blood_type_ = g_object_get_data (G_OBJECT(button_co), "blood_type");
    height_ = g_object_get_data (G_OBJECT(button_co), "height");
    weight_ = g_object_get_data (G_OBJECT(button_co), "weight");
    hla_ = g_object_get_data (G_OBJECT(button_co), "hla");
    plasmapherese_ = g_object_get_data (G_OBJECT(button_co), "plasmapherese");
    smoke_ = g_object_get_data (G_OBJECT(button_co), "smoke");
    enter_bloc_ = g_object_get_data (G_OBJECT(button_co), "enter_bloc");
    clamping_ = g_object_get_data (G_OBJECT(button_co), "clamping");
    notes_ = g_object_get_data (G_OBJECT(button_co), "notes");

    last_name = gtk_entry_get_text(last_name_);
    first_name = gtk_entry_get_text(first_name_);
    sex = gtk_entry_get_text(sex_);
    old = gtk_entry_get_text(old_);
    blood_type = gtk_entry_get_text(blood_type_);
    height = gtk_entry_get_text(height_);
    weight = gtk_entry_get_text(weight_);
    hla = gtk_entry_get_text(hla_);
    plasmapherese = gtk_entry_get_text(plasmapherese_);
    smoke = gtk_entry_get_text(smoke_);
    enter_bloc = gtk_entry_get_text(enter_bloc_);
    clamping = gtk_entry_get_text(clamping_);
    notes = gtk_entry_get_text(notes_);


    lung lung_comparate;
    addLungsStruct(&lung_comparate,last_name, first_name, sex, old,blood_type, height, weight, hla, plasmapherese, smoke,enter_bloc,clamping,notes);
    compare_bloodType(&lung_comparate);

}


void button_addLungs(GtkWidget * addLungsWindow, GtkWidget * main_box, GtkWidget * last_name, GtkWidget * first_name, GtkWidget * sex, GtkWidget * old, GtkWidget * blood_type,GtkWidget * height, GtkWidget * weight, GtkWidget * hla, GtkWidget * plasmapherese, GtkWidget * smoke,GtkWidget * enter_bloc,GtkWidget * clamping,GtkWidget * notes)
{
    GtkWidget * button_co;
    /* Bouton avec un label */
    button_co = gtk_button_new_with_label(" Comparaison ");


    /* Connexion du signal "clicked" du bouton */

    g_object_set_data(G_OBJECT(button_co), "last_name", last_name);
    g_object_set_data(G_OBJECT(button_co), "first_name", first_name);
    g_object_set_data(G_OBJECT(button_co), "sex", sex);
    g_object_set_data(G_OBJECT(button_co), "old", old);
    g_object_set_data(G_OBJECT(button_co), "blood_type", blood_type);
    g_object_set_data(G_OBJECT(button_co), "height", height);
    g_object_set_data(G_OBJECT(button_co), "weight", weight);
    g_object_set_data(G_OBJECT(button_co), "hla", hla);
    g_object_set_data(G_OBJECT(button_co), "plasmapherese", plasmapherese);
    g_object_set_data(G_OBJECT(button_co), "smoke", smoke);
    g_object_set_data(G_OBJECT(button_co), "enter_bloc", enter_bloc);
    g_object_set_data(G_OBJECT(button_co), "clamping", clamping);
    g_object_set_data(G_OBJECT(button_co), "notes", notes);



    g_signal_connect(G_OBJECT(button_co), "clicked", G_CALLBACK(validate_addLungs), (GtkWidget*) addLungsWindow);

    gtk_box_pack_start (GTK_BOX (main_box), button_co, FALSE, FALSE, 0);



}

void formLungs(GtkWidget * addLungsWindow,GtkWidget * main_box)
{
    GtkWidget * label;
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


    /* Creation du premier GtkFrame */
    label = gtk_frame_new("Ajout d'un poumon");
    gtk_box_pack_start(GTK_BOX(main_box), label, TRUE, FALSE, 0);



    label = gtk_label_new("Nom  :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    last_name = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), last_name, TRUE, TRUE, 0);

    label = gtk_label_new(" Prenom :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    first_name = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), first_name, TRUE, TRUE, 0);

    label = gtk_label_new("Sexe :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    sex = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), sex, TRUE, TRUE, 0);

    label = gtk_label_new("Age : ");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    old = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), old, TRUE, TRUE, 0);

    label = gtk_label_new("Groupe sanguin :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    blood_type = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), blood_type, TRUE, TRUE, 0);

    label = gtk_label_new("Taile (en cm)");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    height = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), height, TRUE, TRUE, 0);

    label = gtk_label_new("Poids( en kg) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    weight = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), weight, TRUE, TRUE, 0);

    label = gtk_label_new("Date de naissance (JJ/MM/AAAA) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    hla = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), hla, TRUE, TRUE, 0);

    label = gtk_label_new("Plasmapherese :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    plasmapherese = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), plasmapherese, TRUE, TRUE, 0);

    label = gtk_label_new("Fumeur( 1 oui, 0 non");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    smoke = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), smoke, TRUE, TRUE, 0);

    label = gtk_label_new("Entrer au bloc :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    enter_bloc = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), enter_bloc, TRUE, TRUE, 0);

    label = gtk_label_new("Clampage :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    clamping = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), clamping, TRUE, TRUE, 0);


    label = gtk_label_new("Notes (optionnels) : ");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    notes = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), notes, TRUE, TRUE, 0);



    /* Creation et insertion des elements contenus dans le premier GtkFrame */


 button_addLungs(addLungsWindow, main_box,last_name,first_name, sex,old,blood_type, height, weight, hla, plasmapherese, smoke,enter_bloc,clamping,notes);

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
    gtk_window_resize(GTK_WINDOW(LungAddWindow), 200,200);

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


