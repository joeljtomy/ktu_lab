#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, n;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
	return (rear == n - 1);
}

void printQueue(int queue[]) {
	if (front == -1) {
		printf("Queue empty.");
		return;
	}
	int i;
	printf("[");
	for (i = front; i < rear + 1; i++) {
		if (i == rear)
			printf("%d", queue[i]);
		else
			printf("%d, ", queue[i]);
	}
	printf("]");
}

int main() {
	printf("Enter size of the queue: ");
	scanf("%d", &n);
	int queue[n], choice, value;
	printf("\nQueue created.");

	while (1) {
		printf("\n\nOperations Menu:\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if (isFull()) {
				printf("Queue is full. Cannot enqueue");
				break;
			}

			if (isEmpty())
				front = 0;
			rear++;
			printf("Enter item to push: ");
			scanf("%d", &value);
			queue[rear] = value;

			printf("%d enqueued to the queue", value);
			break;
		case 2:
			if (isEmpty()) {
				printf("Queue is empty. Cannot dequeue");
				break;
			}

			printf("%d dequeued from the queue", queue[front]);

			if (front == rear) {
				front = -1;
				rear = -1;
			}
			else {
				front++;
			}
			break;
		case 3:
			printQueue(queue);
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
