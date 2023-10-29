#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isBlank (char * line)
{
  char * ch;
  int is_blank = -1;

  // Iterate through each character.
  for (ch = line; *ch != '\0'; ++ch)
  {
    if (!isspace(*ch))
    {
      // Found a non-whitespace character.
      is_blank = 0;
      break;
    }
  }

  return is_blank;
}

int main(void)
{
    FILE *f = fopen("input", "r");

    char line[100];
    int max = 0;
    int curr = 0;
    while (fgets(line, sizeof(line), f) != NULL)
    {
        if (isBlank(line))
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
