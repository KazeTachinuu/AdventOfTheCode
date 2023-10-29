#include <stdio.h>
#include <stdlib.h>

int CalculateScore(char *line)
{
    int score = 0;
    char player1 = line[0];
    char player2 = line[2];

    switch (player2)
    {
    case 'X':
        score = 1 + (player1 == 'A') * 3 + (player1 == 'C') * 6;
        break;

    case 'Y':
        score = 2 + (player1 == 'A') * 6 + (player1 == 'B') * 3;
        break;

    case 'Z':
        score = 3 + (player1 == 'B') * 6 + (player1 == 'C') * 3;
        break;
    }
    return score;
}

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[100];
    int score = 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        score += CalculateScore(line);
    }

    printf("%d\n", score);
    fclose(f);
}
