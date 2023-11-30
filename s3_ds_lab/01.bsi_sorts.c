// 1.  Develop a C program to implement insertion sort, Selection sort and bubble sort.

#include <stdio.h>
#include <stdlib.h>

int i, j;

void insertionSort(int arr[], int n) {
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (i = 0; i < n - 1; i++) {
        int smallest = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallest])
                smallest = j;
        }
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int i, n, choice;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n], original[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
        original[i] = arr[i];
    }

    printf("Original array: ");
    printArray(original, n);

    printf("Sorted array using Insertion sort: ");
    insertionSort(arr, n);
    printArray(arr, n);
    for (i = 0; i < n; i++)
        arr[i] = original[i];

    printf("Sorted array using Selection sort: ");
    selectionSort(arr, n);
    printArray(arr, n);
    for (i = 0; i < n; i++)
        arr[i] = original[i];

    printf("Sorted array using Bubble sort: ");
    bubbleSort(arr, n);
    printArray(arr, n);
    for (i = 0; i < n; i++)
        arr[i] = original[i];

    return 0;
}

/*Algorithm
Step 1: Start
Step 2: Declare variables n, opt.
Step 3: Read the size of the array n from the user.
Step 4: Declare arrays arr[n].
Step 5: Read array elements into arr[].
Step 6: Repeat the steps 7 to 12 in loop
Step 7: Display the menu for sorting options:
         Bubble Sort (1)
         Selection Sort (2)
         Insertion Sort (3)
         Exit (4)
     7.2: Read the user's choice into opt.
Step 8: If opt is 1:
     8.1 Perform the Bubble Sort algorithm:
       - Compare each element with its adjacent element and swap if needed.
       - Repeat this process until the array is sorted.
     8.2 Print the sorted array.
Step 9: Else if opt is 2:
     9.1 Perform the Selection Sort algorithm:
       - Find the smallest element and swap it with the first unsorted element.
       - Repeat this process for the remaining unsorted portion of the array.
     9.2 Print the sorted array.
Step 10: Else if opt is 3:
     10.1 Perform the Insertion Sort algorithm:
        - Divide the array into a sorted and an unsorted region.
        - Take elements from the unsorted region and insert them into their correct position in the sorted region.
     10.2 Print the sorted array.
Step 11: Else if opt is 4:
     11.1 Exit the loop.
Step 12: Else:
     12.1 Print "Invalid choice!!!"
Step 13: Stop
*/
