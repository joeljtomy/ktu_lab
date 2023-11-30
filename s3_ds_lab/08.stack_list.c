//8.  Develop a program to perform stack operations using linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *top = NULL;

void push() {
	int data;
	printf("Enter the data for new node: ");
    scanf("%d", &data);
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
	    exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
    printf("%d pushed successfully\n", data);
}

void pop() {
    if (top != NULL) {
        printf("%d poped successfully\n", top->data);
        top = top->link;
	} else printf("Stack Underflow!");
}

void showStack() {
    Node *current = top;
    if (current == NULL) {
        printf("Stack is empty.");
        return;
    }
    printf("Stack: ");
    while (current != NULL) {
        if (current->link == NULL) printf("%d", current->data);
		else printf("%d > ", current->data);
        current = current->link;
    }
}

int main() {
    int choice, data;
    printf("\nStack created.");
    while (1) {
        printf("\n\nOperations Menu:\n");
        printf("1. Push\n2. Pop\n");
        printf("3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        	push();
        	showStack();
			break;
        case 2:
        	pop();
        	showStack();
			break;
        case 3:
            showStack();
			break;
        case 4:
        	printf("Exiting program!\n");
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