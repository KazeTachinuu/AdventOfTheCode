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

    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        int range11 = 0;
        int range12 = 0;
        int range21 = 0;
        int range22 = 0;

        int i = 0;
        char num[4];
        while (line[i] != '-')
        {
            num[i] = line[i];
            i++;
        }
        num[i] = '\0';
        range11 = atoi(num);
        int j = 0;
        i++;

        num[0] = 0;
        num[1] = 0;
        num[2] = 0;

        while (line[i] != ',')
        {
            num[j] = line[i];
            i++;
            j++;
        }
        range12 = atoi(num);

        num[0] = 0;
        num[1] = 0;
        num[2] = 0;

        j = 0;
        i++;
        while (line[i] != '-')
        {
            num[j] = line[i];
            i++;
            j++;
        }
        range21 = atoi(num);
        num[0] = 0;
        num[1] = 0;
        num[2] = 0;

        j = 0;
        i++;
        while (line[i] != '\0')
        {
            num[j] = line[i];
            j++;
            i++;
        }
        range22 = atoi(num);
        if (range11 <= range21 && range12 >= range22)
        {
            /* printf("%d %d %d %d\n", range11, range12, range21, range22); */
            count++;
        }
        else if (range21 <= range11 && range22 >= range12)
        {
            /* printf("%d %d %d %d\n",range11,range12,range21,range22); */
            count++;
        }
    }
    printf("%d\n", count);

    fclose(f);
}
