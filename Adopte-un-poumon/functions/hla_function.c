#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hla_function.h"
#include "addLungs_fonctions.h"

void hla_function(lung * lung_comparate)
{
    char* hla_donator;
    char test[10];
    char test1[10];
    hla_donator = malloc(sizeof(char)*50);
    strcpy(hla_donator,lung_comparate->hla);
    //hla hlaStruct;
    //addHlaStruct(&hlaStruct);

    sscanf(hla_donator,"%s %s",test,test1);
puts(test);
puts(test1);





}




