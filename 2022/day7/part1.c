#include <stdio.h>
#include <stdlib.h>


int lenstr(char *line)
{
    int i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        i++;
    }
    return i;
}

void GetDirName(char* line, char * dir){
    int index = 5;
    int i = 0;
     while (line[index] != '\n') {
            dir[i++] = line[index++];
     }
     dir[i] = '\0';
} 


int main(void)
{
    FILE *f = fopen("input", "r");

    char line[300];
    while (fgets(line, sizeof(line), f) != NULL)
    {
        
        char dir[20];
        if (line[2] == 'c') {
            GetDirName(line,dir);
            printf("cd %s\n",dir);
        }
        else if (line[2] == 'l') {
            HandleLs();
        }
        
    }

    fclose(f);
}
