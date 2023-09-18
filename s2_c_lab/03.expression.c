#include <stdio.h>

int main() {
    int a, b, c, d, e, f, g, result;

    printf("Enter the values of a, b, c, d, e, f and g :");
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

    result = ((a-b/c*d+e)*(f+g));
    
    printf("Result of ((a-b/c+d+e)*(f+g)) = %d\n", result);
    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables a, b, c, d, e, f, g and result.
Step 3: Read values of a, b, c, d, e, f and g.
Step 4: Calculate expression ((a-b/c*d+e)*(f+g)) and assign the value to result.
        result ← ((a-b/c*d+e)*(f+g))
Step 5: Display the result
Step 6: Stop
*/
