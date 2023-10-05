// 2.  Design a program to Implement Quick sort and Merge sort.

#include <stdio.h>
#include <stdlib.h>

int i, j;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary arrays
        int L[n1], R[n2];

        // Copy data to temporary arrays L[] and R[]
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        // Merge the temporary arrays back into arr[l..r]
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the index of the pivot element
        int pivot = arr[high]; // Pivot
        int i = (low - 1);     // Index of smaller element

        for (int j = low; j < high; j++)
        {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        // Place the pivot element at its correct position
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;
        // Sort the elements on the left and right of the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
