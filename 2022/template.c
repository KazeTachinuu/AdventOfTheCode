#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <day>\n",argv[0]);
        return 1;
    }

    char input[11] = "inputs/";
    strcat(input,argv[1]); 

    FILE *f = fopen(input,"r");

}
