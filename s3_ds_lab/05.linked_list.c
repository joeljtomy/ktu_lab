// 5.  Create a menu driven program to implement singly linked list operations with options
//     for insertion, deletion, search and traversal.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while ((*temp).next != NULL)
        {
            temp = (*temp).next;
        }
        (*temp).next = newNode;
    }
}

void deleteNode(Node **head, int data)
{
    if (*head == NULL)
    {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && (*temp).data == data)
    {
        *head = (*temp).next;
        free(temp);
        return;
    }

    while (temp != NULL && (*temp).data != data)
    {
        prev = temp;
        temp = (*temp).next;
    }

    if (temp == NULL)
    {
        printf("Data not found. Unable to delete.\n");
        return;
    }

    (*prev).next = (*temp).next;
    free(temp);
}

void searchNode(Node *head, int data)
{
    int position = 0;
    Node *current = head;
    while (current != NULL)
    {
        if ((*current).data == data)
        {
            printf("Data found at position %d.\n", position);
            return;
        }
        current = (*current).next;
        position++;
    }
    printf("Data not found in the list.\n");
}

void traverseList(Node *head)
{
    Node *current = head;
    if (current == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while (current != NULL)
    {
        printf("%d, ", (*current).data);
        current = (*current).next;
    }
}

int main()
{
    Node *head = NULL;
    int choice, data;
    printf("\nLinked list created");

    while (1)
    {
        printf("\nOperations Menu:\n");
        printf("1. Insert node | 2. Delete node | 3. Search node | 4. Traverse list | 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 3:
            printf("Enter data to search: ");
            scanf("%d", &data);
            searchNode(head, data);
            break;
        case 4:
            traverseList(head);
            break;
        case 5:
            printf("Exiting program.\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/*
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