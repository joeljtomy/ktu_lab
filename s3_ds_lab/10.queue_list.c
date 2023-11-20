//10. Perform queue operations using linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *queue = NULL;
int front = -1, rear = -1;

void enqueue() {
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
    if (queue == NULL) {
    	queue = newNode;
	} else {
		Node *ptr = queue;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
    ptr->next = newNode;
    }
    printf("Node inserted successfully\n");
}

void dequeue() {
	queue = queue->next;
	printf("Node Deleted successfully\n");
}

void showQueue() {
    Node *current = queue;
    if (current == NULL) {
        printf("Queue is empty.");
        return;
    }
    printf("Queue: ");
    while (current != NULL) {
        if (current->next == NULL) printf("%d", current->data);
		else printf("%d > ", current->data);
        current = current->next;
    }
}

int main() {
    int choice, data;
    printf("\nQueue created.");
    while (1) {
        printf("\n\nOpeations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        	enqueue();
        	showQueue();
			break;
        case 2:
        	dequeue();
        	showQueue();
			break;
        case 3:
            showQueue();
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