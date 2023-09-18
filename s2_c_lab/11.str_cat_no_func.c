#include <stdio.h>

int main() {
    char str1[100];
    char str2[100];
    int i = 0, j = 0;

    printf("Enter the first string: ");
    gets(str1);
    
    printf("Enter the second string: ");
    gets(str2);
    
    int k = 0;
    while (str1[k] != '\0') k++;
    i = 0;
    while (str2[i] != '\0') {
        str1[k] = str2[i];
        k++;
        i++;
    }
    str1[k] = '\0';

    printf("Concatenated string: %s\n", str1);

    return 0;
}