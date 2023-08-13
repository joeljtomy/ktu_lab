#include <stdio.h>

int factRecursive(int num) {
    if (num <= 1) return 1;
    else return num * factRecursive(num - 1);
}

int factNormal(int num) {
    int i, result = 1;
    for(i = 1;i <= num;i++) result *= i;
    return result;
}

int main() {
    int num, factorial;

    printf("Enter a number: ");
    scanf("%d", &num);
    
    factorial = factRecursive(num);
    printf("Factorial using recursive function = %d\n", factorial);
    factorial = factNormal(num);
    printf("Factorial using Non recursive function = %d\n", factorial);

    return 0;
}
