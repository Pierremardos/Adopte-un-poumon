
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CPT_header.h"
#include "addLungs_fonctions.h"

double cptT(int height,int sex)
{
    double cptTheorical;

    if(sex == 1 )
    {
        cptTheorical = (height*7.992)-7.081;
    }
    if(sex == 2 )
    {
        cptTheorical = (height*6.602)-5.791;
    }
    return cptTheorical;

}

double ratioCptT(int height,int sex, double cptDonator)
{
    int ratioCptTheaorical;
    ratioCptTheaorical = cptT(height,sex)/cptDonator;
    return ratioCptTheaorical;
}
/*
double ratioCptR(double cptDonator, double cptPatient)
{
    int ratioCptReal;
    ratioCptReal = cptPatient/cptDonator;
    return ratioCptReal;
}
*/

int validation(double ratioCpt)
{
    if (ratioCpt < 1.2)
    {
        if (ratioCpt > 0.9)
        {
            return 0;// bon match
        }
        else
        {
            return -1;  // to small
        }
    }
    else
    {
        return 1; // to big
    }



}



    double result_cpt(lung * lung_comparate)
    {
        char cpt [10] = "cpt =";
        char or[5] = " OR ";
        int height=0;
        int sex=0;
        double cpt_lung=0;

        string result;
        result = malloc(sizeof(char)*50);
        height = atoi(lung_comparate->height);
        sex = atoi(lung_comparate->sex);
        cpt_lung = cptT(height,sex);
        return cpt_lung;
    }
