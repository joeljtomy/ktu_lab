// 14. Apply Queue and stack in Breadth First Search and Depth First Search respectively.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct Edge {
    int data;
    struct Edge *link;
} Edge;

typedef struct Node {
    int data;
    struct Edge *edges;
    struct Node *link;
} Node;

Node *graph;

void addNode(int vertex) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = vertex;
    newNode->edges = NULL;
    newNode->link = graph;
    graph = newNode;
}

void addEdge(Edge **edges, int edge) {
    Edge *newEdge = malloc(sizeof(Edge));
    newEdge->data = edge;
    newEdge->link = *edges;
    *edges = newEdge;
}

Node *findNode(int vertex) {
    Node *ptr = graph;
    while (ptr != NULL && ptr->data != vertex)
        ptr = ptr->link;
    return ptr;
}

int front = -1, rear = -1;
int queue[SIZE];

void enqueue(int value) {
    if (front == -1) front++;
    queue[++rear] = value;
}

void BFS(int start) {
    int visited[SIZE], len = 0, i, found = 0;

    printf("\nBFS starting from vertex %d: ", start);
    enqueue(start);
    while (!(front == -1 || front == rear + 1)) {
        int item = queue[front++];
        visited[len++] = item;
        printf("%d ", item);
        Node *vertex = findNode(item);
        Edge *ptr = vertex->edges;
        while (ptr != NULL) {
            for (i = 0; i < len; i++) {
                if (visited[i] == ptr->data) {
                    found = 1;
                    break;	
				}
            }
            if (!found) {
                for (i = front; i < rear + 1; i++) {
                    if (queue[i] == ptr->data) {
                    	found = 1;
                        break;
					}
                }
            }
            if (!found) enqueue(ptr->data);
            else found = 0;
            ptr = ptr->link;
        }
    }
}

void DFS(int start) {
    int stack[SIZE], top = -1, visited[SIZE], len = 0, i, found = 0;
    printf("\nDFS starting from vertex %d: ", start);
    stack[++top] = start;
    printf("%d ", start);
    visited[len++] = start;
    while (top != -1) { 
        int currentVertex = stack[top];
        Node *vertexNode = findNode(currentVertex);
        Edge *ptr = vertexNode->edges;
        while (ptr != NULL) {
            for (i = 0; i < top + 1; i++) {
                if (stack[i] == ptr->data) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                for (i = 0; i < len; i++) {
                    if (visited[i] == ptr->data) {
                    	found = 1;
			            break;
					}      
                }
            }
            if (!found) {
            	stack[++top] = ptr->data;
            	printf("%d ", ptr->data);
                visited[len++] = ptr->data;
                break;
			} else found = 0;
            ptr = ptr->link;
        }
        if (ptr == NULL) stack[top--];
    }
}

int main() {
    int i, vertex, vertices, edges, start, end, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    for (i = 0; i < vertices; i++) {
        printf("Enter vertex %d: ", i + 1);
        scanf("%d", &vertex);
        addNode(vertex);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: start end):\n");
    for (i = 0; i < edges; i++) {
        printf("%d: ", i + 1);
        scanf("%d %d", &start, &end);
        Node *ptr = graph;
        while (ptr != NULL && ptr->data != start)
            ptr = ptr->link;
        addEdge(&ptr->edges, end);
        ptr = graph;
        while (ptr != NULL && ptr->data != end)
            ptr = ptr->link;
        addEdge(&ptr->edges, start);
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(startVertex);
    DFS(startVertex);

    return 0;
}

/*Algorithm
Step 1: Start.

*/
