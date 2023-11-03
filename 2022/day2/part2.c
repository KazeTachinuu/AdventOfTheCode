#include <stdio.h>
#include <stdlib.h>

int CalculateScore(char *line)
{
    int score = 0;
    char player1 = line[0];
    char player2 = line[2];

    switch (player2)
    {
    case 'Z':
        score =
            6 + (player1 == 'A') * 2 + (player1 == 'B') * 3 + (player1 == 'C');
        break;

    case 'Y':
        score =
            3 + (player1 == 'A') + (player1 == 'B') * 2 + (player1 == 'C')*3;
        break;

    case 'X':
        score = (player1 == 'A') * 3 + (player1 == 'B') + (player1 == 'C')*2;
        break;
    }
    return score;
}

int main(void)
{
    FILE *f = fopen("inputs/2", "r");

    char line[100];
    int score = 0;

    while (fgets(line, sizeof(line), f) != NULL)
    {
        score += CalculateScore(line);
    }

    printf("%d\n", score);
    fclose(f);
}
