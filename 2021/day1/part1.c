#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[300];
    int previousValue = 0;
    int count = -1; // Because the first Value is not supposed to be counted
    while (fgets(line, sizeof(line), f))
    {
        int currValue = atoi(line);
        if (currValue > previousValue)
            count++;
        previousValue = currValue;
    }
    printf("%d\n", count);

    fclose(f);
}
