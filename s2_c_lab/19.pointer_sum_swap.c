#include <stdio.h>

void swap(int *p1, int *p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main() {
	int num1, num2;
	int *p1=&num1, *p2=&num2;
    printf("Enter the 1st number: ");
    scanf("%d", &num1);
    printf("Enter the 2nd number: ");
    scanf("%d", &num2);
	printf("Sum of %d and %d is = %d\n", *p1, *p2, *p1+*p2);
	printf("Before swapping num1 = %d, num2 = %d\n", *p1, *p2);
	swap(p1,p2);
	printf("After swapping num1 = %d, num2 = %d\n", *p1, *p2);
	return 0;
}