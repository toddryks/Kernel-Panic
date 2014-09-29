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
