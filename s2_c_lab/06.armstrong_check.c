#include <stdio.h>
#include <math.h>

int main() {
    int num, tempNum, remainder, result = 0, d = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    tempNum = num;

    while (tempNum != 0) {
        tempNum /= 10;
        d++;
    }

    tempNum = num;

    while (tempNum != 0) {
        remainder = tempNum % 10;
        result += pow(remainder, d);
        tempNum /= 10;
    }

    if (result == num) printf("%d is an Armstrong number.\n", num);
    else printf("%d is not an Armstrong number.\n", num);

    return 0;
}



/*Algorithm
Step 1: Start
Step 2: Declare variables num, tempNum, remainder, d and result.
Step 3: Initialize variables
        result ← 0
        d ← 0  
Step 4: Read num from the user.
Step 5: tempNum  num
Step 6: Repeat the steps until tempNum != 0
     6.1 tempNum ← tempNum/10
     6.2 d ← d+1
Step 7: tempNum ← num
Step 8: Repeat the steps until tempNum != 0
     8.1 remainder ← tempNum%10
     8.2 result ← result + pow(remainder, d);
     8.3 tempNum ← tempNum/10
Step 9: If result == num
           Display num is an Armstrong number.
        else
           Display num is not an Armstrong number.
Step 10: Stop 
*/
