/* ****************************************************************
* Project 2:  System Calls, Kernel Modules & Schedulers
* Developers:  Edward Skrod, Todd Ryks
* Date:  October 2, 2014
* Part 1
* A C program that uses exactly 20 more system calls than are used
* in an empty program. On the MCH202 lab computers, an empty C 
* program has exactly 26 system calls. Our program, tracetest, 
* produces 46 system calls.
**************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 0;
    char *str;

    str = (char *) malloc(sizeof("=== System Call Number Loop ==") + 1);
    strcpy(str, "=== System Call Number Loop ===");
    printf("%s\n\n", str);
    fflush(stdout);
    free(str);

    for (i = 1; i <= 15; ++i)
    {
        printf("%d\n", i);
        fflush(stdout);
    }

    return 0;
}
