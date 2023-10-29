#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int Contains(char c, char *line)
{
    int i = 0;
    while (line[i] != '\0' && line[i] != c)
    {
        i++;
    }
    return line[i] == c;
}

int lenstr(char *line)
{
    int i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        i++;
    }
    return i;
}

int CalculatePriority(char c)
{
    if (c < 97)
        return c - 38;
    else
        return c - 96;
}

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[100];
    int sum = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        int len = lenstr(line);
        char part1[len / 2 + 1];
        char part2[len / 2 + 1];
        int i = 0;
        while (i < len / 2)
        {
            part1[i] = line[i];
            i++;
        }
        part1[i] = '\0';

        int j = 0;
        while (j < len / 2)
        {
            part2[j] = line[i];
            i++;
            j++;
        }
        part2[j] = '\0';

        i = 0;
        while (part1[i] != '\0' && !Contains(part1[i], part2))
        {
            i++;
        }

        sum += CalculatePriority(part1[i]);
    }
    printf("%d\n", sum);

    fclose(f);
}
