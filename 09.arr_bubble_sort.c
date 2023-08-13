#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variable n, temp, i and j.
Step 3: Initialize variables
        i, j ← 0
Step 4: Read n from the user.
Step 5: Declare array arr with size n
Step 6: Read elements of arr from the user.
Step 7: Repeat the steps until i < n-1
     7.1 Repeat the steps until j < n-i-1
     7.1.1 If arr[j] > arr[j + 1]
            temp ← arr[j]
            arr[j] ← arr[j + 1]
            arr[j + 1] ← temp
     7.1.2 j ← j+1
     7.2 i ← i+1
Step 8: Display sorted arr.
Step 9: Stop 
*/