#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[300];
    int v1 = 0;
    int v2 = 0;
    int v3 = 0;
    int count = 0;
    int mod = 0;

    //Initialize Data
    while (mod < 3)
    {
        fgets(line, sizeof(line), f);

        switch (mod)
        {
        case 0:
            v1 = atoi(line);
            break;
        case 1:
            v2 = atoi(line);
            break;

        case 2:
            v3 = atoi(line);
            break;
        }

        mod++;
    }

    //Calculate for the rest of the input
    while (fgets(line, sizeof(line), f) != NULL)
    {
        int current = atoi(line);

        int sum1 = v1 + v2 + v3;
        int sum2 = v2 + v3 + current;

        if (sum2 > sum1)
            count++;

        v1 = v2;
        v2 = v3;
        v3 = current;

        mod++;
    }

    printf("%d\n", count);

    fclose(f);
}
