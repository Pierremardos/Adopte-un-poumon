#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Bloodtype_header.h"
#include "zerogets.h"

string bloodCmp(char bloodType[3])
{
    char a[5] = "'a'";
    char b[5] = "'b'";
    char o[5] = "'o'";
    char ab[5] = "'ab'";
    char and[10] = " AND ";
    string result;

    if (!strcmp(bloodType, "a")&& strlen(bloodType)==1)
    {
        result = malloc(20*sizeof(char));
        strcpy(result, a);
        strcat(result, and);
        strcat(result, o);
        return result;
    }
    else if (!strcmp(bloodType,"b")&& strlen(bloodType)==1)
    {
        result = malloc(20*sizeof(char));
        strcpy(result, b);
        strcat(result, and);
        strcat(result, o);
        return result;
    }
    else if (!strcmp(bloodType,"o")&& strlen(bloodType)==1)
    {
        result = malloc(20*sizeof(char));
        strcpy(result, a);
        strcat(result, and);
        strcat(result, b);
        strcat(result, and);
        strcat(result, ab);
        strcat(result, and);
        strcat(result, o);
        return result;

    }
    else if (!strcmp(bloodType,"ab")&& strlen(bloodType)==2)
    {
        result = malloc(3*sizeof(char));
        strcpy(result, ab);
        return result;
    }
    else
    {
        printf("Ce n'est pas un groupe sanguin : ");
        zerofgets(bloodType, 3);
        bloodCmp(bloodType);
    }

}
