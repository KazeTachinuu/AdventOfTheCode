#include <stdio.h>

int Contains(char c, char *part2, char *part3)
{
    int i = 0;
    int j = 0;
    while (part2[i] != '\0' && part2[i] != c)
    {
        i++;
    }
    if (part2[i] == c)
    {
        while (part3[j] != '\0' && part3[j] != c)
        {
            j++;
        }
    }

    return part2[i] == c && part3[j] == c;
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

void Inject(char *line, char *lines)
{
    int i = 0;
    while (line[i] != '\n')
    {
        lines[i] = line[i];
        i++;
    }
    lines[i] = '\0';
}

int main(void)
{
    FILE *f = fopen("inputs/3", "r");

    char line[300];
    int sum = 0;
    int curr = 0;
    char part1[100];
    char part2[100];
    char part3[100];
    while (fgets(line, sizeof(line), f) != NULL)
    {
        switch (curr % 3)
        {
        case 0:
            Inject(line, part1);
            break;
        case 1:
            Inject(line, part2);
            break;
        case 2:
            Inject(line, part3);
            break;
        }
        curr++;
        if (curr % 3 == 0)
        {
            int i = 0;
            while (part1[i] != '\0' && !Contains(part1[i],part2,part3)){
                i++;
            }
            sum+=CalculatePriority(part1[i]);
        }
    }
    printf("%d\n", sum);

    fclose(f);
}
