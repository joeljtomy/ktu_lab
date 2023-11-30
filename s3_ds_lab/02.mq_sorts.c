// 2.  Design a program to Implement Quick sort and Merge sort.

#include <stdio.h>
#include <stdlib.h>

int i, j;

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        int n1 = middle - start + 1;
        int n2 = end - middle;

        int left[n1], right[n2];

        for (i = 0; i < n1; i++)
            left[i] = arr[start + i];
        for (j = 0; j < n2; j++)
            right[j] = arr[middle + 1 + j];

        i = j = 0;
        int k = start;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j])
                arr[k] = left[i++];
            else
                arr[k] = right[j++];
            k++;
        }
        while (i < n1)
           arr[k++] = left[i++];
        while (j < n2)
           arr[k++] = right[j++];
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = start;
        int pivotValue = arr[end];

        for (i = start; i < end; i++) {
            if (arr[i] < pivotValue)
                swap(&arr[i], &arr[pivotIndex++]);
        }

        swap(&arr[pivotIndex], &arr[end]);
        
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

void printArray(int arr[], int n) {
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n], copy[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
        copy[i] = arr[i];
    }

    printf("Original array: ");
    printArray(arr, n);

    printf("Sorted array using merge sort: ");
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    printf("Sorted array using quick sort: ");
    quickSort(copy, 0, n - 1);
    printArray(copy, n);

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Read the size of the array n from the user.
Step 3: Declare arrays arr[n] and copy[n].
Step 4: Read array elements into arr[] and copy it to copy[].
Step 5: Perform the Merge Sort algorithm on arr[] array:
       - If the array has only one or zero elements, it is already sorted.
       - If the array has more than one element:
         - Divide the array into two roughly equal halves.
         - Recursively apply Merge Sort to each half.
         - Merge the sorted halves back into one sorted array.
Step 6: Print the sorted arr[] array.
Step 7: Perform the Quick Sort algorithm on copy[] array:
       - If the array has one or zero elements, it is already considered sorted.
      - If the array has more than one element:
         - Choose a 'pivot' element from the array.
         - Partition the array such that elements smaller than the pivot are on the left,
           and larger ones are on the right.
         - Recursively apply Quick Sort to the subarrays on the left and right of the pivot.
Step 8: Print the sorted copy[] array.
Step 9: Stop
*/
