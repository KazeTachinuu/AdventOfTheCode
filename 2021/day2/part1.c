#include <stdio.h>

int main(void)
{
    int hor = 0;
    int depth = 0;

    FILE *f = fopen("input", "r");
    char line[10000];
    while (fgets(line, sizeof(line), f))
    {
        switch (line[0])
        {
        case 'f':
            hor += line[8] - 48;
            break;
        case 'd':
            depth += line[5] - 48;
            break;
        case 'u':
            depth -= line[3] - 48;
        }
    }

    printf("%d\n", hor * depth);
}
