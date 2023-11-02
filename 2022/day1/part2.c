#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[100];
    int max = 0;
    int max2 = 0;
    int max3 = 0;
    int curr = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        if (line[0] == '\n')
        {
            if (curr > max)
            {
                max3 = max2;
                max2 = max;
                max = curr;
            }
            else if (curr > max2)
            {
                max3 = max2;
                max2 = curr;
            }
            else if (curr > max3)
            {
                max3 = curr;
            }
            curr = 0;
        }
        else
            curr += atoi(line);
    }

    if (curr > max)
    {
        max3 = max2;
        max2 = max;
        max = curr;
    }
    else if (curr > max2)
    {
        max3 = max2;
        max2 = curr;
    }
    else if (curr > max3)
    {
        max3 = curr;
    }
    printf("%d %d %d\n", max, max2, max3);
    printf("%d\n", max + max2 + max3);
    fclose(f);
}
