// 3.  Create Program for Linear Search.

#include <stdio.h>

int main()
{
    int i, n, key, count = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("%d is found at index %d\n", key, i);
            count++;
        }
    }

    if (count)
        printf("Total %d appearances of %d\n", count, key);
    else
        printf("%d is not in the array\n", key);

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables n, key and count = 0.
Step 3: Read n from the user.
Step 4: Declare array arr with size n.
Step 5: Read elements of arr from the user.
Step 6: Read key from the user.
Step 7: Repeat the steps until i < n
     7.1 If arr[i] == key
            Display Element found at index 'i'.
            count = count + 1
     7.2 i ← i+1
Step 8: If count
           Display count
        else
           Display Element not found
Step 9: Stop
*/