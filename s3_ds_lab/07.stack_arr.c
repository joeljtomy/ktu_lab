// 7.  Develop a program to perform stack operations using array.

#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
	int i;
	printf("[");
    for (i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]");
}

int main() {
	int n;
	printf("Enter size of the stack: ");
	scanf("%d", &n);

	int stack[n], top = -1, choice, data;
	printf("\nStack created.");

	while (1) {
		printf("\n\nOperations Menu:\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Status\n");
		printf("4. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (top < n - 1) {
				top += 1;
				printf("Enter item to push: ");
				scanf("%d", &data);
				stack[top] = data;
				printArray(stack, top + 1);
			}
			else {
				printf("Stack Overflow!");
			}
			break;
		case 2:
			if (top > -1) {
				stack[top] = 0;
				top -= 1;
				printArray(stack, top + 1);

			}
			else {
				printf("Stack Underflow!");
			}
			break;
		case 3:
			if (top == -1) {
				printf("Stack Empty");
			}
			else if (top == n - 1) {
				printf("Stack Full");
			}
			else {
				printf("Top: %d", top);
			}
			break;
		case 4:
			printf("Program exited!!!\n");
			exit(0);
		default:
			printf("Invalid choice! Please try again.");
		}
	}

	return 0;
}

/*Algorithm
Step 1: Start.

*/
