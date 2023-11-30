//10. Perform queue operations using linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue() {
	int data;
	printf("Enter the data for new node: ");
    scanf("%d", &data);
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
	    exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    if (rear == NULL) rear = front = newNode;
	else rear = rear->link = newNode;
    printf("%d enqueued successfully\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue empty can't dequeue.\n");
        return;
    }
    printf("%d dequeued successfully\n", front->data);
	if (front->link == NULL) rear = NULL;
    front = front->link;
}

void showQueue() {
    Node *current = front;
    if (current == NULL) {
        printf("Queue is empty.");
        return;
    }
    printf("Queue: ");
    while (current != NULL) {
        if (current->link == NULL) printf("%d", current->data);
		else printf("%d > ", current->data);
        current = current->link;
    }
}

int main() {
    int choice, data;
    printf("\nQueue created.");
    while (1) {
        printf("\n\nOpeations Menu:\n");
		printf("1. Enqueue\n2. Dequeue\n");
		printf("3. Display\n4. Exit\n");
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
