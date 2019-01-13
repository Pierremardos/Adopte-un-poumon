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

#include "Bloodtype_header.h"

#include "CPT_header.h"




void compare_bloodType(lung* lung_comparate)
{
    double cpt_lung=0;
    cpt_lung = result_cpt(lung_comparate);
    printf(" \n %lf \n",cpt_lung);

    string result_blood;
    string req_select;
    req_select = malloc(sizeof(char)*500);

    result_blood = malloc(sizeof(char)*30);
    result_blood = bloodCmp(lung_comparate->blood_type);
//Déclaration du pointeur de structure de type MYSQL
    MYSQL mysql;
    //Initialisation de MySQL
    mysql_init(&mysql);
    //Options de connexion
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion réussie...
    if(mysql_real_connect(&mysql, "localhost","root", "", "pulmonax", 0, NULL, 0))
    {
        //Requête qui sélectionne tout dans ma table patients ou le bloodtype est egal a celui qu'on vient d'ecrire
        sprintf(req_select,"SELECT * FROM patients WHERE bloodtype = %s AND `cpt`/ '%lf' < 1.2 AND `cpt`/ '%lf' > 0.9",result_blood,cpt_lung,cpt_lung);
        puts(req_select);
        mysql_query(&mysql,req_select);
        free(result_blood);
        free(req_select);
        //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;

        unsigned int i = 0;
        unsigned int num_champs = 0;
        unsigned long *lengths;


        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(&mysql);

        //On récupère le nombre de champs
        num_champs = mysql_num_fields(result);

        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
            //On déclare un pointeur long non signé pour y stocker la taille des valeurs

            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);

            //On fait une boucle pour avoir la valeur de chaque champs
            for(i = 0; i < num_champs; i++)
            {
                //On ecrit toutes les valeurs
            printf("[%.*s] ", (int) lengths[i], row[i] ? row[i] : "NULL");




            }
            printf("\n");
        }



        //Libération du jeu de résultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);

    }
    else  //Sinon ...
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD!");
    }

}
