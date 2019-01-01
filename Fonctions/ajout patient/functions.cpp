#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winsock.h>
#include <MYSQL/mysql.h>
#include "header.h"
typedef char* string;


void zerofgets(string str, int size)
{
    fflush(stdin);
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

void addPatient (string name,string surname, string birth, string dateInscription, long height, long weight, string bloodType, string HLA, string plasmapherese)
{
 string request;
 int size;
 size = sizeof(name) + sizeof(surname) + sizeof(birth) + sizeof(dateInscription) + sizeof(height) + sizeof(weight) + sizeof(bloodType) + sizeof(HLA) + sizeof(plasmapherese) + 50;

 request = malloc(sizeof(name) + sizeof(surname) + sizeof(birth) + sizeof(dateInscription) + sizeof(height) + sizeof(weight) + sizeof(bloodType) + sizeof(HLA) + sizeof(plasmapherese) + 50);
}
void mysql(string request)
{
        MYSQL mysql;
        mysql_init(&mysql);
        mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
        if(mysql_real_connect(&mysql, "localhost","root", "", "pulmonax", 0, NULL, 0))
        {
            mysql_query(&mysql, request);
            mysql_close(&mysql);
        }
        else
        {
            printf("Erreur connexion");

        }
}
