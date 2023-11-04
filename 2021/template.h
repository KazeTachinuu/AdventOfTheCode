#ifndef TEMPLATE_H

#define TEMPLATE_H

#include <stdio.h>

int atoi(char *line)
{
    int res = 0;
    int sign = 1;

    if (*line == '-')
    {
        sign = -1;
        line++;
    }

    while (*line != '\n')
    {
        res = 10 * res + *line++ - '0';
    }

    return res * sign;
}

#endif /* end of include guard: TEMPLATE_H */
