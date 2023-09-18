#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &(*(arr + i))); 
    }

    printf("Elements of the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i)); 
    }
    
    printf("\n");

    return 0;
}
