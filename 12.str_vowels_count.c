#include <stdio.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0, spaces = 0;
    int i = 0;

    printf("Enter a string: ");
    gets(str);

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' ||
            str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
            vowels++;
        } else if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z')) {
            consonants++;
        } else if (str[j] == ' ') {
            spaces++;
        }
    }

    printf("String: %s\n", str);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of spaces: %d\n", spaces);

    return 0;
}
