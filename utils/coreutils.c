#include "coreutils.h"
#include <stdio.h>

int help()
{
    puts("xsh - a lightweight shell");
    puts("written by cakeman105");
    puts("xsh comes with ABSOLUTELY NO WARRANTY");

    return 0;
}

int see(char * str)
{
    if (str)
        puts(str);
    return 0;
}