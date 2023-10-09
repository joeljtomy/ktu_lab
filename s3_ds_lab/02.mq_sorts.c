// 2.  Design a program to Implement Quick sort and Merge sort.

#include <stdio.h>
#include <stdlib.h>

int i, j;

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        int i, j, k;
        int n1 = middle - start + 1;
        int n2 = end - middle;

        int left[n1], right[n2];

        for (i = 0; i < n1; i++)
            left[i] = arr[start + i];
        for (j = 0; j < n2; j++)
            right[j] = arr[middle + 1 + j];

        i = 0;
        j = 0;
        k = start;
        while (i < n1 || j < n2)
        {
            if (j >= n2 || left[i] <= right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else if (i >= n1 || left[i] > right[j])
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivotIndex = start; 
        int pivotValue = arr[end];

        for (i = start; i < end; i++) {
            if (arr[i] < pivotValue) {
                swap(&arr[i], &arr[pivotIndex]);
                pivotIndex++;
            }
        }

        swap(&arr[pivotIndex], &arr[end]);

        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
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
        original[i] = arr[i];
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
            mergeSort(arr, 0, n - 1);
            break;
        case 2:
            quickSort(arr, 0, n - 1);
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
      - If the array has only one or zero elements, it is already sorted.
      - If the array has more than one element:
            - Divide the array into two roughly equal halves.
            - Recursively apply Merge Sort to each half.
            - Merge the sorted halves back into one sorted array.
     8.2 Print the sorted array.
Step 9: Else if opt is 2:
     9.1 Perform the Quick Sort algorithm:
      - If the array has one or zero elements, it is already considered sorted.
      - If the array has more than one element:
            - Choose a 'pivot' element from the array.
            - Partition the array such that elements smaller than the pivot are on the left,
              and larger ones are on the right.
            - Recursively apply Quick Sort to the subarrays on the left and right of the pivot.
     9.2 Print the sorted array.
Step 10: Else if opt is 3:
     10.1 Exit the loop.
Step 11: Else:
     11.1 Print "Invalid choice!!!"
Step 12: Stop
*/
