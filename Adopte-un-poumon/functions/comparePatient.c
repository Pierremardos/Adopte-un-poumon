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
    int smoke=0;
    //D�claration des objets
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    //D�claration du pointeur de structure de type MYSQL
    MYSQL mysql;
    unsigned int i = 0;
    unsigned int num_champs = 0;
    unsigned long *lengths;
    double cpt_lung=0;
    // INTIALISATION DES VARIABLES CHAR QUI VONT STOCKER LES DIFFERENTS HLA
    char hla1[20];
    strcpy(hla1,"p");
    char hla2[20];
    strcpy(hla2,"p");
    char hla3[20];
    strcpy(hla3,"p");
    char hla4[20];
    strcpy(hla4,"p");
    char hla5[20];
    strcpy(hla5,"p");
    char hla6[20];
    char * hla_donator;

    // INITIALISATION DES VARIABLES CHAR QUI VONT STOCKER LES DIFFERENTS PLASMAPHERESE
    char plasma1[5];
    strcpy(plasma1,"p");
    char plasma2[5];
    strcpy(plasma2,"p");
    char plasma3[5];
    strcpy(plasma3,"p");
    char plasma4[5];
    strcpy(plasma4,"p");
    char plasma5[5];
    strcpy(plasma5,"p");
    char * plasma_donator;
    // REQUETE QUI VA RECUPERER LE RATIO DU POUMON

    cpt_lung = result_cpt(lung_comparate);
    string result_blood;
    string req_select;
    req_select = malloc(sizeof(char)*500);
    result_blood = malloc(sizeof(char)*30);

    // Comparaison du groupe sanguin entre patients et donneur
    result_blood = bloodCmp(lung_comparate->blood_type);

    // Comparaison si les patients et donneurs fument ou non
    smoke = smoke_func(lung_comparate);

    // Comparaison des HLA du patient et du donneur
    hla_donator = malloc(sizeof(char)*100);
    strcpy(hla_donator,lung_comparate->hla);
    sscanf(hla_donator,"%s %s %s %s %s %s",hla1,hla2,hla3,hla4,hla5,hla6);

    // Comparaison du Plasma du patient et du donneur
    plasma_donator = malloc(sizeof(char)*100);
    strcpy(plasma_donator,lung_comparate->plasmapherese);
    sscanf(plasma_donator,"%s %s %s %s %s %s",plasma1,plasma2,plasma3,plasma4,plasma5);

    //Initialisation de MySQL
    mysql_init(&mysql);

    //Options de connexion
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    //Si la connexion r�ussie...
    if(mysql_real_connect(&mysql, "localhost","root", "", "pulmonax", 0, NULL, 0))
    {
        hla_function(lung_comparate);
        //Requ�te qui s�lectionne tout dans ma table patients ou le bloodtype est egal a celui qu'on vient d'ecrire
        sprintf(req_select,"SELECT * FROM patients WHERE (`smoke` = '%d' ) AND (bloodtype = %s) AND (`cpt`/ '%lf' < 1.2) AND (`cpt`/ '%lf' > 0.9) AND (INSTR(hla, '%s' )=0) AND (INSTR(hla, '%s' )=0) AND (INSTR(hla, '%s') =0 ) AND (INSTR(hla, '%s' )=0) AND (INSTR(hla, '%s' )=0) AND (INSTR(plasmapherese, '%s' )>=0) AND (INSTR(plasmapherese, '%s' )>=0) AND (INSTR(plasmapherese, '%s') >=0 ) AND (INSTR(plasmapherese, '%s' )>=0) AND (INSTR(plasmapherese, '%s' )>=0)",smoke,result_blood,cpt_lung,cpt_lung,hla1,hla2,hla3,hla4,hla5,plasma1,plasma2,plasma3,plasma4,plasma5);
        puts(req_select);
        mysql_query(&mysql,req_select);
        //On met le jeu de r�sultat dans le pointeur result
        result = mysql_use_result(&mysql);
        //On r�cup�re le nombre de champs
        num_champs = mysql_num_fields(result);
        //Tant qu'il y a encore un r�sultat ...
        while ((row = mysql_fetch_row(result)))
        {
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
        //Lib�ration du jeu de r�sultat
        mysql_free_result(result);
        //Fermeture de MySQL
        mysql_close(&mysql);
    }
    else  //Sinon ...
    {
        printf("Une erreur s'est produite lors de la connexion � la BDD!");
    }

    // FREE MALLOC
    free(result_blood);
    free(req_select);

}
