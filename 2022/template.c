#include <stdio.h>
#include <stdlib.h>


int lenstr(char *line)
{
    int i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        i++;
    }
    return i;
}




int main(void)
{
    FILE *f = fopen("input", "r");

    char line[300];
    int var = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        
    }
    printf("%d\n", var);

    fclose(f);
}
