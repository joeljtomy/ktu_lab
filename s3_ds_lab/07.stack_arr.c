// 7.  Develop a program to perform stack operations using array.

#include <stdio.h>
#include <stdlib.h>

void input(char msg[],int *location) {
    printf(msg);
    scanf("%d", location);
}

int main() {
	int n;
	input("Enter size of the stack: ", &n);
    int stack[n], top = -1, choice, data;
    printf("\nStack created.");
    while (1) {
        printf("\n\nOperations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Status\n");
        printf("4. Exit\n");
        input("Enter your choice: ", &choice);

        switch (choice) {
        case 1:
        	if (top < n - 1) {
        		top += 1;
        		input("Enter item to push: ", &data);
        	    stack[top] = data;
        	    printf("%d Pushed", data);
			} else {
				printf("Stack Overflow!");
			}
			break;
        case 2:
        	if (top > -1) {
        		printf("%d Poped", stack[top]);
        		stack[top] = 0;
        		top -= 1;
			} else {
				printf("Stack Underflow!");
			}
			break;
        case 3:
            if (top == -1) {
        		printf("Stack Empty");
			} else if (top == n - 1) {
				printf("Stack Full");
			} else {
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
