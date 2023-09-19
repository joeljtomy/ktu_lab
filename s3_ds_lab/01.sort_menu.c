#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, i, j, opt;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    while (1)
    {
        printf("\nSelect operation from menu\n");
        printf("\t\tMENU\nl.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            bubbleSort(arr, n);
            printArray(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            printArray(arr, n);
            break;
        case 3:
            insertionSort(arr,n);
            printArray(arr, n);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!!!\n");
        }
    }

    return 0;
}
