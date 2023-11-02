#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[100];
    int max = 0;
    int curr = 0;
    while (fgets(line, sizeof(line), f))
    {
        if (line[0] == '\n')
        {
            max = curr > max ? curr : max;
            curr = 0;
        }
        else
            curr += atoi(line);
    }

    max = curr > max ? curr : max;
    printf("%d\n", max);
    fclose(f);
}
