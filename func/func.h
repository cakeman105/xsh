#include <stdio.h>


char * get_line(FILE * file, int * warningptr);

char ** tokenize(char * line, int * argc);

int run(int argc, char ** argv);