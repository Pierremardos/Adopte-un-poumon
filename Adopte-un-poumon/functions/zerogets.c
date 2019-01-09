#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "zerogets.h"

void zerofgets(string str, int size)
{
    fflush(stdin);
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}
