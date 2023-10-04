// 4.  Create Program for Binary Search.

#include <stdio.h>

int main()
{
    int i, j, n, key, found, index;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1;

    while (low - 1 < high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            found = 1;
            index = mid;
            break;
        }
        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found)
        printf("%d was found at index %d\n", key, index);
    else
        printf("%d is not in the array\n", key);

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables n, key, found and index.
Step 3: Read n from the user.
Step 4: Declare array arr with size n.
Step 5: Read elements of arr from the user.
Step 6: Sort the array arr to perform binary sort.
Step 7: Read key from the user.
Step 8: Declare variables low = 0, mid = n-1/2 and high = n-1.
Step 9: Repeat the steps until break
     9.1 If arr[mid] == key
            found = 1
            index = mid
            break
     9.2 Else if low == mid-1
            break
     9.3 Else if arr[mid] < key
            low = mid
            mid = mid + ((high - mid) / 2)
     9.4 Else if arr[mid] > key
            high = mid
            mid = low + ((high - low) / 2)
Step 10: If found
           Display Element found at index
        else
           Display Element not found
Step 11: Stop
*/