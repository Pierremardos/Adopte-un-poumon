#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "smoke_function.h"
#include "addLungs_fonctions.h"

int smoke_func (lung * lung_comparate)
{

    char * smoke_lung;
    smoke_lung = malloc(sizeof(char)*5);
    int smoke_lung_=0;
    strcpy(smoke_lung,lung_comparate->smoke);
    puts(lung_comparate->smoke);

    smoke_lung_ = atoi(smoke_lung);
    return smoke_lung_;
}
