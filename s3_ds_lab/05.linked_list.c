// 5.  Create a menu driven program to implement singly linked list operations with options
//     for insertion, deletion, search and traversal.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
} Node;

Node *head = NULL;

void insertNode(int position) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    printf("Enter data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->link = NULL;

    if (head == NULL) head = newNode;
    else {
        Node *ptr = head;
        if (position == 1) {
            newNode->link = head;
            head = newNode;
        } else if (position == 2) {
            while (ptr->link != NULL)
                ptr = ptr->link;
            ptr->link = newNode;
        } else {
            int key;
            printf("Enter data of the node after which you want to insert: ");
            scanf("%d", &key);

            while (ptr != NULL && ptr->data != key)
                ptr = ptr->link;

            newNode->link = ptr->link;
            ptr->link = newNode;
        }
    }
    printf("Node inserted successfully.\n");
}

void deleteNode(int position) {
    if (head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    Node *ptr = head;

    if (position == 1) head = head->link;
    else if (position == 2) {
        if (head->link == NULL) {
            free(head);
            head = NULL;
            return;
        }

        while (ptr->link->link != NULL)
            ptr = ptr->link;

        free(ptr->link);
        ptr->link = NULL;
    } else if (position == 3) {
        int key;
        printf("Enter data of the node to delete: ");
        scanf("%d", &key);

        Node *prev = NULL;

        while (ptr != NULL && ptr->data != key) {
            prev = ptr;
            ptr = ptr->link;
        }

        if (ptr == NULL) {
            printf("Node with the given data not found.\n");
            return;
        }

        prev->link = ptr->link;
        free(ptr);
    }
    printf("Node deleted successfully.\n");
}

void search(int data) {
    Node *ptr = head;
    int position = 1;

    while (ptr != NULL && ptr->data != data) {
        ptr = ptr->link;
        position++;
    }

    if (ptr == NULL) printf("Node with the given data not found.\n");
    else printf("Node with data %d found at position %d.\n", data, position);
}

void traverse() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *ptr = head;
    printf("Linked list: ");
    while (ptr != NULL) {
        if (ptr->link == NULL) printf("%d", ptr->data);
		else printf("%d > ", ptr->data);
        ptr = ptr->link;
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\nLinked list operations Menu:\n");
        printf("Insertion:\n  1. At the beginning\n  2. At the end\n  3. After a node\n");
        printf("Deletion:\n  4. At the beginning\n  5. At the end\n  6. A specific node\n");
        printf("7. Search for a node\n8. Traverse the list\n9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3:
                insertNode(choice);
                break;
            case 4:
            case 5:
            case 6:
                deleteNode(choice - 3);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 8:
                traverse();
                break;
            case 9:
                printf("Exiting the program. Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    };

    return 0;
}


/*Algorithm
Step 1: Start.
Step 2: Node Structure:
        Define a structure Node to represent each node in the linked list.
        The structure has two members: data to hold the data and next to point to the next node.
Step 3: Create Node Function (createNode):
        Define a function to create a new node and initialize it with the given data.
        This function allocates memory for a node, sets its data,
        and sets the next pointer to NULL.
Step 4: Insert Node Function (insertNode):
        Define a function to insert a new node at the end of the linked list.
        If the list is empty, set the head to the new node.
        Otherwise, traverse to the end of the list and append the new node.
Step 5: Delete Node Function (deleteNode):
        Define a function to delete a node with a given data value.
        Traverse the list to find the node with the specified data and remove it from the list.
Step 6: Search Node Function (searchNode):
        Define a function to search for a node with a given data value.
        Traverse the list and print the position of the node if found.
Step 7: Traverse List Function (traverseList):
        Define a function to traverse and print the data of all nodes in the linked list.
Step 8: Menu-Driven Program (main):
        Implement a menu-driven program with options for the user to perform various
        operations on the linked list: insert, delete, search, traverse, and exit.
Step 9: Display the menu of operations and prompt the user for their choice.
        Use a switch statement to perform the chosen operation based on the user's input.
Step 10: Main Function:
         Initialize the head of the linked list to NULL.
         Display a welcome message and enter a loop to handle the menu-driven operations.
         The program continues to display the menu and allows the user to perform
         linked list operations until they choose to exit.
*/
