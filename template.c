#include <stdio.h>
#include <stdlib.h>

/*!
 * Copy the line without the \n at the end
 *
 * param line Current line of the input
 */
void Strip(char *line)
{
    int i = 0;
    while (line[i] != '\n')
    {
        i++;
    }
    line[i] = '\0';
}

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[300];
    int var = 0;
    while (fgets(line, sizeof(line), f))
    {

    }
    printf("%d\n", var);

    fclose(f);
}
