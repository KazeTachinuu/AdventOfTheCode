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
    int previousValue = 0;
    int count = -1; // Because the first Value is not supposed to be counted
    while (fgets(line, sizeof(line), f))
    {
        Strip(line);
        int currValue = atoi(line);
        if (currValue > previousValue)
            count++;
        previousValue = currValue;
    }
    printf("%d\n", count);

    fclose(f);
}
