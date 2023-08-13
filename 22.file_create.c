#include <stdio.h>
#include <stdlib.h>

FILE *openFile(char *filename, char *mode) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error opening the file '%s'.\n", filename);
        exit(1);
    }
    return file;
}

int main() {
    FILE *file;
    char filename[100], data[1000];

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    
    file = openFile(filename, "w");

    printf("Enter data to write into the file:\n");
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);

    fclose(file);
    
    file = openFile(filename, "r");

    printf("\nFile content:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }

    fclose(file);

    file = openFile(filename, "a");

    printf("\nEnter data to append to the file (max 1000 characters):\n");
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);

    fclose(file);

    file = openFile(filename, "r");

    printf("\nFile content after appending:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }

    fclose(file);

    return 0;
}
