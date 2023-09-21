#include <stdio.h>
#include <math.h>

int main()
{
    int num, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1)
        isPrime = 0;
    else
        for (i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                isPrime = 0;
                break;
            }
        }

    if (isPrime)
        printf("%d is a prime number\n", num);
    else
        printf("%d is not a prime number\n", num);

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables num, i and isPrime.
Step 3: Initialize variables
        isPrime ← 1
        i ← 2
Step 4: Read num from the user.
Step 5: Repeat the steps until i<=sqrt(num)
     5.1 If remainder of num÷i equals 0
            isPrime ← 0
            Go to step 6
     5.2 i ← i+1
Step 6: If isPrime = 0
           Display num is not prime
        else
           Display num is prime
Step 7: Stop
*/
