#include <stdio.h>

int main() {
    int n, i;
    float sum = 0, average;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = sum / n;

    printf("Sum of the numbers: %f\n", sum);
    printf("Average of the numbers: %f\n", average);

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables n, i, sum and average.
Step 3: Initialize variables
        sum ← 0
Step 4: Read n from the user.
Step 5: Declare array arr with size n
Step 6: Read elements of arr from the user.
Step 7: Repeat the steps until i < n
     7.1 sum ← sum + arr[i]
     7.2 i ← i+1
Step 8: average ← sum / n
Step 9: Display sum and average.
Step 10: Stop 
*/