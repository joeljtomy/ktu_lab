#include <stdio.h>

int main() {
    int a, b, c, largest;

    printf("Enter 3 numbers: ");
    scanf("%d%d%d", &a, &b, &c);

    if (a >= b && a >= c) {
        largest = a;
    } else if (b >= a && b >= c) {
        largest = b;
    } else {
        largest = c;
    }

    printf("The largest number is %d\n", largest);

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables a, b, c and largest.
Step 3: Read values of a, b and c.
Step 4: if a >= b && a >= c 
          largest ← a;
        else if b >= a && b >= c
          largest ← b;
        else 
          largest ← c;
Step 5: Display the largest
Step 6: Stop
*/
