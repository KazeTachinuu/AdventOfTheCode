#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("input", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open the input file.\n");
        return 1;
    }

    const int lineLength = 12;
    const int numLine = 1000;

    char lines[numLine][lineLength];
    int lineCount = 0;

    char lineBuffer[lineLength + 2];  // +2 to account for the newline and null terminator

    while (fgets(lineBuffer, sizeof(lineBuffer), file) && lineCount < numLine) {
        strncpy(lines[lineCount], lineBuffer, lineLength);
        lines[lineCount][lineLength] = '\0';
        lineCount++;
    }

    fclose(file);

    int gamma = 0;
    int epsilon = 0;

    for (int bitIndex = 0; bitIndex < lineLength; bitIndex++) {
        int ones = 0;
        int zeros = 0;

        for (int lineIndex = 0; lineIndex < lineCount; lineIndex++) {
            char bit = lines[lineIndex][bitIndex];
            if (bit == '0') {
                zeros++;
            } else {
                ones++;
            }
        }

        char resultBit = (ones > zeros) ? '1' : '0';
        gamma = (gamma << 1) | (resultBit - '0');
    }

    int num2 = 1 << lineLength;
    epsilon = num2 - 1 - gamma;
    int product = epsilon * gamma;

    printf("Product: %d\n", product);

    return 0;
}

