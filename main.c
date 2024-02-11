/**
 * xsh - a lightweight shell
 * @author cakeman105
 * @date 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/unistd.h>
#include "utils/coreutils.h"

#define BUFFER_SIZE 32
#define LINE_DELIMS " \t\r\n\a"

/**
 * gets string from stdin and ends once a newline char is encountered
 * @param file input
 * @return line
*/
char * getLine(FILE * file)
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

char ** tokenize(char * line)
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

    return params;
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
        line = getLine(stdin);
        if (!strcasecmp(line, "exit"))
            break;
        
        params = tokenize(line);

        if (!strcasecmp(params[0], "see"))
            see(params[1]);

        if (!strcasecmp(params[0], "help"))
            help();

        free(line);
        free(params);
    }

    free(line);
    puts("Goodbye!");
    return 0;
}