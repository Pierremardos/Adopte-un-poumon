
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CPT_header.h"

double cptT(double height,int sex)
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

double ratioCptT(double height,int sex, double cptDonator)
{
    int ratioCptTheaorical;
    ratioCptTheaorical = cptT(height,sex)/cptDonator;
    return ratioCptTheaorical;
}

double ratioCptR(double cptDonator, double cptPatient)
{
    int ratioCptReal;
    ratioCptReal = cptPatient/cptDonator;
    return ratioCptReal;
}

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
