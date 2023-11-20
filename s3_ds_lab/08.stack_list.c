//8.  Develop a program to perform stack operations using linked list. #include <stdio.h>

#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *stack = NULL;

void push() {
	int data;
	printf("Enter the data for new node: ");
    scanf("%d", &data);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
	    exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->next = stack;
    stack = newNode;
    printf("Node inserted successfully\n");
}

void pop() {
	stack = stack->next;
	printf("Node Deleted successfully\n");
}

void showStack() {
    Node *current = stack;
    if (current == NULL) {
        printf("Stack is empty.");
        return;
    }
    printf("Stack: ");
    while (current != NULL) {
        if (current->next == NULL) printf("%d", current->data);
		else printf("%d > ", current->data);
        current = current->next;
    }
}

int main() {
    int top = -1, choice, data;
    printf("\nStack created.");
    while (1) {
        printf("\n\nOperations Menu:\n");
        printf("1. Push\n2. Pop\n");
        printf("3. Status\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        	top += 1;
        	push();
        	showStack();
			break;
        case 2:
        	if (top > -1) {
        		pop();
        		top -= 1;
        		showStack();
			} else {
				printf("Stack Underflow!");
			}
			break;
        case 3:
            if (top == -1) {
        		printf("Stack Empty");
			} else {
				showStack();
				printf("\nTop: %d", top);
			}
			break;
        case 4:
        	printf("Exiting program!!!\n");
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