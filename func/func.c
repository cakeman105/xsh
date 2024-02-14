#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../utils/coreutils.h"
#include "func.h"

#define BUFFER_SIZE 32
#define LINE_DELIMS " \t\r\n\a"
#define COMMAND_COUNT 5

char * get_line(FILE * file, int * warningptr)
{

    char c = fgetc(file);
    char * line = calloc(1, sizeof(char));
    line[0] = c;
    
    int i = 1;
    while ((c = fgetc(file)) != '\n')
    {
        if (c == EOF)
        {
            *warningptr = 1;
            break;
        }

        line = realloc(line, (i + 2) * sizeof(char));
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return line;
}

char ** tokenize(char * line, int * argc)
{
    char ** params = calloc(1, sizeof(char *));
    char * token = strtok(line, LINE_DELIMS);
    params[0] = token;

    int i = 1;
    while ((token = strtok(NULL, LINE_DELIMS)))
    {
        params = realloc(params, (i + 2) * sizeof(char *));
        params[i] = token;
        i++;
    }

    *argc = i;

    return params;
}

int run(int argc, char ** argv)
{
    //DO NOT CHANGE THE ORDER OF THE FOLLOWING ARRS
    const char * cmds[COMMAND_COUNT] = {"help", "see", "bye", "cloc", "cat"};
    int (*funcs[]) (int, char **) = {&help, &see, &bye, &cloc, &cat};

    for (int i = 0; i < COMMAND_COUNT; i++)
    {
        if (!strcasecmp(cmds[i], argv[0]))
        {
            return funcs[i](argc, argv);
        }
    }

    return -1; //return -1 only for non-existing programs
}