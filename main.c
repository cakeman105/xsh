/**
 * xsh - a lightweight shell
 * @author cakeman105
 * @date 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include "utils/coreutils.h"

#define BUFFER_SIZE 32
#define LINE_DELIMS " \t\r\n\a"
#define COMMAND_COUNT 4

/**
 * gets string from stdin and ends once a newline char is encountered
 * @param file input
 * @return line
*/
char * get_line(FILE * file)
{
    char c = fgetc(file);
    char * line = calloc(1, sizeof(char));
    line[0] = c;
    
    int i = 1;
    while ((c = fgetc(file)) != '\n')
    {
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
    const char * cmds[COMMAND_COUNT] = {"help", "see", "bye", "cloc"};
    int (*funcs[]) (int, char **) = {&help, &see, &bye, &cloc};

    for (int i = 0; i < COMMAND_COUNT; i++)
    {
        if (!strcasecmp(cmds[i], argv[0]))
        {
            return funcs[i](argc, argv);
        }
    }

    return -1;
}

int main(int argc, char ** argv)
{
    puts("xsh - a lightweight shell");
    puts("-------------------------");
    char * line;
    char ** params;

    while (1)
    {
        printf("xsh ~~~> ");
        line = get_line(stdin);
        int argc = 0;
        params = tokenize(line, &argc);

        int status = run(argc, params);
        if (status == -1)
            fprintf(stderr, "Invalid argument!\n");
        else if (status == -2)
            break;

        printf("[%d] ", status);

        free(line);
        free(params);
    }
    
    free(params);
    free(line);
    puts("args free()'d successfully. Goodbye!");
    return EXIT_SUCCESS;
}