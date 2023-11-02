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
    int previousValue1 = 0;
    int previousValue2 = 0;
    int count = -1; // Because the first Value is not supposed to be counted
    int mod = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        Strip(line);
        int currValue = atoi(line);
        if (mod > 3) {
            if (currValue + previousValue + previousValue1 + previousValue2 > previousValue + previousValue1 + previousValue2 ) 
        }
        switch (mod % 3)
        {
        case 0:
            previousValue = currValue;
            break;
        case 1:
            previousValue1 = currValue;
            break;
        case 2:
            previousValue2 = currValue;
            break;
        }


        mod++;
    }
    printf("%d\n", count);

    fclose(f);
}
