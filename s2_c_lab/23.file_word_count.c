#include <stdio.h>

int main() {
    FILE *input, *output;
    char inputFilename[100], outputFilename[100];
    int charCount = 0, wordCount = 0, lineCount = 0, inWord = 0;
    char ch;

    printf("Enter the input filename: ");
    fgets(inputFilename, sizeof(inputFilename), stdin);

    input = fopen(inputFilename, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while ((ch = fgetc(input)) != EOF) {
        charCount++;

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (ch == '\n') lineCount++;
            inWord = 0;
        } else {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        }
    }
    if (ch != '\n') lineCount++;
    
    fclose(input);
    
    printf("Enter the output filename: ");
    fgets(outputFilename, sizeof(outputFilename), stdin);

    output = fopen(outputFilename, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    fprintf(output, "Number of characters: %d\n", charCount);
    fprintf(output, "Number of words: %d\n", wordCount);
    fprintf(output, "Number of lines: %d\n", lineCount);

    fclose(output);

    printf("Statistics have been stored in the output file.\n");

    return 0;
}
