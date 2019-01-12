#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#define EXEMPLE_1 0
#define EXEMPLE_2 1
#define EXEMPLE_3 2
#include "Graphical_header.h"
#include "addPatients_header.h"
#include "config_files.h"
#include "addLungs_fonctions.h"


void  impossible_open_file(GtkWidget * mainWindow)
{
    GtkWidget * dialog;

dialog = gtk_message_dialog_new (mainWindow,
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "Impossible d'ouvrir le fichier de configuration : "
                                 );
gtk_dialog_run (GTK_DIALOG (dialog));
gtk_widget_destroy (dialog);
}

void button_change_files(GtkWidget * mainWindow,GtkWidget * main_box, gint iExemple)
{
    GtkWidget * button;
    switch(iExemple)
    {
    default:
    case EXEMPLE_3:
        /* Bouton avec un label */
        button = gtk_button_new_with_label("Modifier le fichier de configuration");
        break;

    }
    /* Connexion du signal "clicked" du bouton */
    g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(changes_files),(GtkWidget*) mainWindow );

    gtk_box_pack_end  (GTK_BOX (main_box), button, TRUE, FALSE, 0);


}
void  leave(gpointer data, guint callback_action,GtkWidget *widget)
{
    GtkWidget * ask_leave;

    ask_leave = gtk_message_dialog_new(GTK_WINDOW(data),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_QUESTION,
        GTK_BUTTONS_YES_NO,
        "Voulez vous vraiment\n"
        "quitter le programme?");

    switch(gtk_dialog_run(GTK_DIALOG(ask_leave)))
    {
    case GTK_RESPONSE_YES:
        gtk_main_quit();
        break;
    case GTK_RESPONSE_NONE:
    case GTK_RESPONSE_NO:
        gtk_widget_destroy(ask_leave);
        break;
    }
}

static GtkItemFactoryEntry MenuItem[] = {
    { "/_Fichier", NULL, NULL, 0, "<Branch>" },
    { "/Fichier/_Lister les patients", NULL, NULL, 0, "<StockItem>", GTK_STOCK_FIND },
    { "/Fichier/_Nouveaux patients", "<ctrl>A", addPatientWindow, 0, "<StockItem>", GTK_STOCK_ADD },
    { "/Fichier/_Nouveaux poumons", "<ctrl>S", addLungsWindow, 0, "<StockItem>", GTK_STOCK_ADD },
    { "/Fichier/_Fermer", "<ctrl>F", leave, 0, "<StockItem>", GTK_STOCK_CLOSE }
};

static gint iNbMenuItem = sizeof(MenuItem) / sizeof(MenuItem[0]);



void toolbar_window(GtkWidget * window,GtkWidget * main_box)
{
    GtkWidget * toolbar;
    GtkItemFactory * Factory;
    GtkAccelGroup * keys;

    /* Création de la table d'accélération */
    keys = gtk_accel_group_new();

    /* Création du menu */
    Factory = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<main>", keys);
    /* Récupération des éléments du menu */
    gtk_item_factory_create_items(Factory, iNbMenuItem, MenuItem, (GtkWidget*)window);
    /* Récupération du widget pour l'affichage du menu */
    toolbar = gtk_item_factory_get_widget(Factory, "<main>");
    /* Ajout du menu en haut de la fenêtre */
    gtk_box_pack_start(GTK_BOX(main_box), toolbar, FALSE, FALSE, 0);
    /* Association des raccourcis avec la fenêtre */
    gtk_window_add_accel_group(GTK_WINDOW(window), keys);



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

void main_program(int argc, char ** argv)
{
  GtkWidget * main_box = NULL;
    GtkWidget * window=NULL;

    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);

    /* Création de la fenêtre */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle évènementielle */
    gtk_widget_show(window);

    /* On definit le titre de la fenêtre */
    gtk_window_set_title(GTK_WINDOW(window), "Transplantation de poumons");

    /* Définition de la position */
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER_ALWAYS  );

    /* Définition d'un icone de la fenêtre */
    gtk_window_set_icon_from_file(GTK_WINDOW(window),"organes.jpg",NULL);

    /* On définit la taile de la fenêtre par défault */
    gtk_window_resize(GTK_WINDOW(window), 1000,1000);

    /* Maximiser la fenêtre */
    gtk_window_maximize (GTK_WINDOW(window));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(window));

    /* Création de la GtkBox verticale */
    main_box = gtk_vbox_new(FALSE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(window), main_box);

    // AJOUT DE LA TOOLBAR DANS LA FENETRE
        toolbar_window(window,main_box);

    gtk_widget_show_all(window);
    gtk_main();


}


void listUsers (gchar * login, gchar * password,GtkWidget * second_window,GtkWidget * main_box,int argc,char **argv)
{
    unsigned int i = 0;
    unsigned int num_champs = 0;
    static int counter=0;



    // mysql();

    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    if(mysql_real_connect(&mysql, "localhost","root", "", "pulmonax", 0, NULL, 0))
    {

        char query[500];
        //Requête qui sélectionne tout dans ma table scores

        //Requête qui sélectionne tout dans ma table users
        sprintf (query,"SELECT login,password FROM users WHERE login = ('%s') AND password = ('%s')",login,password);
        mysql_query(&mysql,query);

        //Déclaration des pointeurs de structure
        MYSQL_RES *result = NULL;
        MYSQL_ROW row = NULL;


        //On met le jeu de résultat dans le pointeur result (maintenant on utilise mysql_store_result
        result = mysql_store_result(&mysql);

        //On récupère le nombre de champs
        num_champs = mysql_num_fields(result);

        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
            counter++;
            //On déclare un pointeur long non signé pour y stocker la taille des valeurs
            unsigned long *lengths;


            //On stocke cette taille dans le pointeur
            lengths = mysql_fetch_lengths(result);
        }

       if (counter)
            {
                main_program(argc,argv);
                //Libération du jeu de résultat
                mysql_free_result(result);

                //Fermeture de MySQL
                mysql_close(&mysql);

            }
            else
            {
                display_error_message(second_window,main_box);
                // listUsers (login,password,second_window,main_box);
            }


    }


}




void validate_connexion(GtkWidget *button_co,GtkWidget * second_window,GtkWidget * main_box,int argc,char **argv)
{

    GtkEntry * login_co;
    GtkEntry * password_co;
    const gchar *login_connexion;
    const gchar *password_connexion;
    login_co = g_object_get_data (G_OBJECT(button_co), "login");
    password_co = g_object_get_data (G_OBJECT(button_co), "password");



    login_connexion = gtk_entry_get_text(login_co);
    password_connexion = gtk_entry_get_text(password_co);


    // CONNEXION A LA BASE DE DONNEES POUR VERIFIER LES BON IDENTIFIANTS
    listUsers(login_connexion,password_connexion,second_window,main_box,argc,argv);




}
void button_connexion(GtkWidget * second_window,GtkWidget * main_box,gint iExemple,GtkWidget *login,GtkWidget *password)
{
    GtkWidget * button_co;
    switch(iExemple)
    {
    default:
    case EXEMPLE_1:
        /* Bouton avec un label */
        button_co = gtk_button_new_with_label(" Try to connect ! ");
        break;

    }
    /* Connexion du signal "clicked" du bouton */

    g_object_set_data(G_OBJECT(button_co), "login", login);
    g_object_set_data(G_OBJECT(button_co), "password", password);
    g_signal_connect(G_OBJECT(button_co), "clicked", G_CALLBACK(validate_connexion), (GtkWidget*) second_window);

    gtk_box_pack_start (GTK_BOX (main_box), button_co, FALSE, FALSE, 0);


}

void connexion(GtkWidget * SecondWindow,GtkWidget * main_box)
{
    GtkWidget * login;
    GtkWidget * pFrame;
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
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    /* Creation du GtkEntry avec 8 caracteres maximum */
    password = gtk_entry_new_with_max_length(8);

    /* Mode mot de passe */
    gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);

    /* Modification du caractere affiche */
    gtk_entry_set_invisible_char(GTK_ENTRY(password), '*');
    /* Insertion du GtkEntry dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(main_box), password, FALSE, FALSE, 0);

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

    /* Création de la fenêtre */
    SecondWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(SecondWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle évènementielle */
    gtk_widget_show(SecondWindow);

    /* On definit le titre de la fenêtre */
    gtk_window_set_title(GTK_WINDOW(SecondWindow), "Connexion :");

    /* Définition de la position */
    gtk_window_set_position(GTK_WINDOW(SecondWindow), GTK_WIN_POS_CENTER_ALWAYS  );

    /* Définition d'un icone de la fenêtre */
    gtk_window_set_icon_from_file(GTK_WINDOW(SecondWindow),"organes.jpg",NULL);

    /* On définit la taile de la fenêtre par défault */
    gtk_window_resize(GTK_WINDOW(SecondWindow), 500,500);

    /* Maximiser la fenêtre */
    gtk_window_maximize (GTK_WINDOW(SecondWindow));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(SecondWindow));

    /* Création de la GtkBox verticale */
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


char * convert_text (gchar * text)
{
    text= g_locale_to_utf8(text, -1, NULL, NULL, NULL);
    return text;
}

void creation_label (GtkWidget * MainWindow,GtkWidget* mainLabel,gchar* convert_mainLabel,gchar * positionLabel, GtkWidget * main_box)
{
    convert_mainLabel = convert_text("ADOPTE UN POUMON \n --------------------------- \n --------------------------- \n       Software by Arthur & Jonas \n --------------------------- \n ");
    mainLabel=gtk_label_new(convert_mainLabel); // Application de la convertion à notre label
    g_free(convert_mainLabel); // Libération de la mémoire

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

    /* Création de la fenêtre */
    MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle évènementielle */
    gtk_widget_show(MainWindow);

    /* On definit le titre de la fenêtre */
    gtk_window_set_title(GTK_WINDOW(MainWindow), "Gestion de transplantation d'organes");

    /* Définition de la position */
    gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER_ALWAYS  );

    /* Définition d'un icone de la fenêtre */
    gtk_window_set_icon_from_file(GTK_WINDOW(MainWindow),"test.png",NULL);

    /* On définit la taile de la fenêtre par défault */
    gtk_window_resize(GTK_WINDOW(MainWindow), 800,800);

    /* Maximiser la fenêtre */
    gtk_window_maximize (GTK_WINDOW(MainWindow));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(MainWindow));

    /* Création de la GtkBox verticale */
    main_box = gtk_vbox_new(TRUE, -50);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(MainWindow), main_box);


    // CREATION DU PREMIER LABEL DE LA FENETRE
    creation_label(MainWindow,mainLabel,convert_mainLabel,positionLabel,main_box);

    // Affichage image du milieu
    first_image(MainWindow,main_box,path_image);

    // BOUTON QUI PERMET DE LANCER LE PROGRAMME
    launch_program(MainWindow,main_box,EXEMPLE_3);

    // BOUTON CONFIGURATION FICHIER
    button_change_files(MainWindow,main_box,EXEMPLE_3);

    gtk_widget_show_all(MainWindow);
    gtk_main();
}
