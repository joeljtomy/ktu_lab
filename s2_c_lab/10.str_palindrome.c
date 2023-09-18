//1. without using library functions

#include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }

    return 1;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);

    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}

/*Algorithm 1


*/

//2. with using library functions

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char rev[100];

    printf("Enter a string: ");
    gets(str);

    strcpy(rev, str);

    strrev(rev);

    int result = strcmp(str, rev);

    if (result == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

/*Algorithm 2



*/