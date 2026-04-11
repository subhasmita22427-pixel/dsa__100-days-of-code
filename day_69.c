#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph array
struct Node* adj[MAX];

// Distance array
int dist[MAX];

// Min Heap Node
struct HeapNode {
    int vertex;
    int distance;
};

// Min Heap
struct HeapNode heap[MAX];
int heapSize = 0;

// Function to swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify (up)
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].distance > heap[i].distance) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify (down)
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].distance < heap[smallest].distance)
        smallest = left;

    if (right < heapSize && heap[right].distance < heap[smallest].distance)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int vertex, int distance) {
    heap[heapSize].vertex = vertex;
    heap[heapSize].distance = distance;
    heapifyUp(heapSize);
    heapSize++;
}

// Extract minimum
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Create new adjacency node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra function
void dijkstra(int V, int src) {
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        struct HeapNode current = pop();
        int u = current.vertex;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }
}

// Main function
int main() {
    int V, E, u, v, w, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(V, src);

    printf("Shortest distances from source:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Distance %d\n", i, dist[i]);
    }

    return 0;
}
