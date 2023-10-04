// 2.  Design a program to Implement Quick sort and Merge sort.

#include <stdio.h>
#include <stdlib.h>

int i, j;

void mergeSort(int arr[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int n)
{
    for (i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int i, n, opt;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n], original[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
        original[i] =   arr[i];
    }

    printf("Original array: ");
    printArray(original, n);

    while (1)
    {
        printf("\nSelect operation from menu\n");
        printf("MENU : l.Merge sort,  2.Quick sort,  3.Exit\n");
        scanf("%d", &opt);
        for (i = 0; i < n; i++)
            arr[i] = original[i];
        switch (opt)
        {
        case 1:
            mergeSort(arr, n);
            break;
        case 2:
            quickSort(arr, n);
            break;
        case 3:
            printf("Program exited.\n");
            exit(0);
        default:
            printf("Invalid choice!!!\n");
            continue;
        }
        printf("Sorted array: ");
        printArray(arr, n);
    }

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables n, opt.
Step 3: Read the size of the array n from the user.
Step 4: Declare arrays arr[n].
Step 5: Read array elements into arr[].
Step 6: Repeat the steps 7 to 11 in loop
Step 7: Display the menu for sorting options:
         Merge Sort (1)
         Quick Sort (2)
         Exit (4)
     7.2: Read the user's choice into opt.
Step 8: If opt is 1:
     8.1 Perform the Merge Sort algorithm:
       - Compare each element with its adjacent element and swap if needed.
       - Repeat this process until the array is sorted.
     8.2 Print the sorted array.
Step 9: Else if opt is 2:
     9.1 Perform the Quick Sort algorithm:
       - Find the smallest element and swap it with the first unsorted element.
       - Repeat this process for the remaining unsorted portion of the array.
     9.2 Print the sorted array.
Step 10: Else if opt is 3:
     10.1 Exit the loop.
Step 11: Else:
     11.1 Print "Invalid choice!!!"
Step 12: Stop
*/
