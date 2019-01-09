#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "addPatients_header.h"




void zerofgets(string str, int size)
{
    fflush(stdin);
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

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
