#include <stdio.h>

int atoi(char *line)
{
    int res = 0;
    int i = 0;
    int sign = 1;
    if (line[0] == '-')
    {
        i++;
        sign = -1;
    }
    while (line[i] != '\n')
    {
        res = res * 10 + line[i++] - '0';
    }
    return res * sign;
}

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[300];
    int count = 0; 
    
    //Initialize Data
    fgets(line, sizeof(line), f);
    int currValue = atoi(line);

    while (fgets(line, sizeof(line), f))
    {
        int previousValue = currValue;
        currValue = atoi(line);
        if (currValue > previousValue)
            count++;
    }
    printf("%d\n", count);

    fclose(f);
}
