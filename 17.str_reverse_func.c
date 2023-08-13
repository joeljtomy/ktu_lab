#include <stdio.h>
#include <string.h>

void strReverse(char str[]) {
    int len = strlen(str), i, j;
    for(i=0,j=len-1;i<j;i++,j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);

    strReverse(str);
    
    printf("Reversed string is: %s\n", str);

    return 0;
}