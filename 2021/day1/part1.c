#include <stdio.h>
#include <stdlib.h>

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
