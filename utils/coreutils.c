#include "coreutils.h"
#include <stdio.h>

int help(char ** argv)
{
    puts("xsh - a lightweight shell");
    puts("written by cakeman105");
    puts("xsh comes with ABSOLUTELY NO WARRANTY");

    return 0;
}

int see(char ** argv)
{
    int i = 1;
    while (argv[i])
        puts(argv[i++]);

    return 0;
}

int bye()
{
    return -2;
}