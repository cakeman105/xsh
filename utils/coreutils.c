#include "coreutils.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

int help(int argc, char ** argv)
{
    puts("xsh - a lightweight shell");
    puts("written by cakeman105");
    puts("xsh comes with ABSOLUTELY NO WARRANTY");

    return 0;
}

int see(int argc, char ** argv)
{
    for (int i = 1; i < argc; i++)
        puts(argv[i]);

    return 0;
}

int bye()
{
    return -2;
}

int cloc()
{
    time_t t = time(NULL);
    printf("%s", (asctime(localtime(&t))));

    return 0;
}