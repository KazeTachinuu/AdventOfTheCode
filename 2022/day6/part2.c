#include <stdio.h>
#include <stdlib.h>

int Contains(char c, char *line, int begin, int end)
{
    int self = -1;
    while (begin <= end)
    {
        if (line[begin] == c)
        {
            if (self == -1)
            {
                self = 0;
            }
            else
            {
                return 1;
            }
        }

        begin++;
    }
    return 0;
}

int IsConsecutive(char *line, int begin, int end)
{
    int index = begin;
    while (index <= end && !Contains(line[index], line, begin, end))
    {
        index++;
    }
    return index > end;
}

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[10000];
    int end;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        int begin = 0;
        end = 13;

        while (line[end] != '\n' && !IsConsecutive(line, begin, end))
        {
            begin++;
            end++;
        }
    }
    printf("%d\n", end+1);

    fclose(f);
}
