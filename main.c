/**
 * xsh - a lightweight shell
 * @author cakeman105
 * @date 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "utils/coreutils.h"
#include "func/func.h"

int main(int argc, char ** argv)
{
    puts("xsh - a lightweight shell");
    puts("-------------------------");
    char * line;
    char ** params;

    while (1)
    {
        printf("xsh ~~~> ");
        line = get_line(stdin, NULL);
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
    perror("free()");
    puts("Goodbye!");
    return EXIT_SUCCESS;
}