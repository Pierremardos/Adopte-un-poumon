#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include <winsock.h>
#include <MYSQL/mysql.h>

#include "comparePatient.h"
#include "zerogets.h"

#include "addLungs_fonctions.h"
#include "comparePatient.h"


void close_mysql(string mysql)
{
    mysql_close(&mysql);

}
void connexion_mysql()
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    mysql_real_connect(&mysql, "localhost","root","", "pulmonax", 0, NULL, 0);

}

void compare_bloodType(lung* lung_comparate)
{
    char req_select[1000];
    char name[20];
    strcpy(name,"o");
//D�claration du pointeur de structure de type MYSQL
    MYSQL mysql;
    //Initialisation de MySQL
    mysql_init(&mysql);
    //Options de connexion
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion r�ussie...
    if(mysql_real_connect(&mysql, "localhost","root", "", "pulmonax", 0, NULL, 0))
    {
        //Requ�te qui s�lectionne tout dans ma table patients ou le bloodtype est egal a celui qu'on vient d'ecrire
        sprintf(req_select,"SELECT id FROM patients WHERE bloodtype = ('%s')",lung_comparate->blood_type);
        mysql_query(&mysql,req_select);
        //D�claration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;
        unsigned long *lengths;


        //On met le jeu de r�sultat dans le pointeur result
        result = mysql_use_result(&mysql);

        //On r�cup�re le nombre de champs
        num_champs = mysql_num_fields(result);

        //Tant qu'il y a encore un r�sultat ...
        while ((row = mysql_fetch_row(result)))
        {
            //On d�clare un pointeur long non sign� pour y stocker la taille des valeurs

            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);

            //On fait une boucle pour avoir la valeur de chaque champs
            for(i = 0; i < num_champs; i++)
            {
                //On ecrit toutes les valeurs
                if (row[i])
                    printf("%.*s", (int) lengths[i], row[i]);
                else
                    printf("NULL");
            }
            printf("\n");
        }

        //Lib�ration du jeu de r�sultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);

    }
    else  //Sinon ...
    {
        printf("Une erreur s'est produite lors de la connexion � la BDD!");
    }

}
