#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter the 1st number: ");
    scanf("%d", &num1);
    printf("Enter the 2nd number: ");
    scanf("%d", &num2);

    printf("%d + %d = %d\n", num1, num2, num1 + num2);

    return 0;
}


/*Algorithm
Step 1: Start
Step 2: Declare variables num1, num2 and sum. 
Step 3: Read values num1 and num2. 
Step 4: Add num1 and num2 and assign the result to sum.
        sum ← num1+num2 
Step 5: Display sum 
Step 6: Stop
*/