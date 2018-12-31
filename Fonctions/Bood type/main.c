#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char * string;

string bloodCmp(char bloodType[2]);
void zerofgets(char * str, int size);


void zerofgets(char * str, int size)
{
    fflush(stdin);
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

string bloodCmp(char bloodType[3])
{
    char a[3] = "a ";
    char b[3] = "b ";
    char o[3] = "o ";
    char ab[3] = "ab";
    string result;

    if (!strcmp(bloodType, "a")&& strlen(bloodType)==1)
    {
        result = malloc(5*sizeof(char));
        strcpy(result, a);
        strcat(result, o);
        return result;
    }
    else if (!strcmp(bloodType,"b")&& strlen(bloodType)==1)
    {
        result = malloc(5*sizeof(char));
        strcpy(result, b);
        strcat(result, o);
        return result;
    }
    else if (!strcmp(bloodType,"o")&& strlen(bloodType)==1)
    {
        result = malloc(9*sizeof(char));
        strcpy(result, a);
        strcat(result, b);
        strcat(result, ab);
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

int main(int argc,char ** argcv)
{
    char bloodLung[2];
    string result;


    printf("Donnez le groupe sanguin du greffon :  ");
    zerofgets(bloodLung,3);
    result = bloodCmp(bloodLung);
    printf("\nLes personne compatible sont de groupe sanguin : %s",result);
    free(result);

}
