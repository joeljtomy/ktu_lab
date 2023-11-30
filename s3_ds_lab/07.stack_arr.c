// 7.  Develop a program to perform stack operations using array.

#include <stdio.h>
#include <stdlib.h>

void printStack(int arr[], int top) {
	int i;
	if (top == -1) printf("Stack Empty");
    else {
	    printf("Stack: ");
        for (i = 0; i <= top; i++)
            printf("%d ", arr[i]);
	}
}

int main() {
	int n;
	printf("Enter size of the stack: ");
	scanf("%d", &n);

	int stack[n], top = -1, choice, data;
	printf("\nStack created.");

	while (1) {
		printf("\n\nOperations Menu:\n");
        printf("1. Push\n2. Pop\n");
        printf("3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (top < n - 1) {
				printf("Enter item to push: ");
				scanf("%d", &data);
				stack[++top] = data;
				printStack(stack, top);
			}
			else printf("Stack Overflow!");
			break;
		case 2:
			if (top > -1) {
				top--;
				printStack(stack, top);
			}
			else printf("Stack Underflow!");
			break;
		case 3:
			printStack(stack, top);
			break;
		case 4:
			printf("Program exited!\n");
			exit(0);
		default:
			printf("Invalid choice!");
		}
	}

	return 0;
}

/*Algorithm
Step 1: Start.

*/
