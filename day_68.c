#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

// enqueue
void enqueue(int x) {
    queue[rear++] = x;
}

// dequeue
int dequeue() {
    return queue[front++];
}

int main() {
    int n, adj[MAX][MAX];
    int indegree[MAX] = {0};
    int topo[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Step 1: Calculate indegree
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Push all indegree 0 nodes
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    // Step 3: BFS
    while (front < rear) {
        int node = dequeue();
        topo[count++] = node;

        for (int j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;

                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }

    // Step 4: Check cycle
    if (count != n) {
        printf("Cycle exists. Topological sort not possible\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}
