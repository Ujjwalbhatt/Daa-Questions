
//Implement problem using Prim's algorithm taking input from user
/*
Sample Input:
0 0 7 5 0 0 0
0 0 8 5 0 0 0
7 8 0 9 7 0 0
5 0 9 0 15 6 0
0 5 7 15 0 8 9
0 0 0 6 8 0 11
0 0 0 0 9 11 0
Output:
Minimum Spanning Weight: 39
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph {
    int V, E;
    int** adjMatrix;
} Graph;

int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int primMST(Graph* graph) {
    int V = graph->V;
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph->adjMatrix[u][v] && mstSet[v] == 0 && graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    int minWeight = 0;
    for (int i = 1; i < V; i++)
        minWeight += graph->adjMatrix[i][parent[i]];

    return minWeight;
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->adjMatrix = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
        graph->adjMatrix[i] = (int*) malloc(V * sizeof(int));

    printf("Enter the source, destination and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph->adjMatrix[src][dest] = weight;
        graph->adjMatrix[dest][src] = weight;
    }

    int minWeight = primMST(graph);
    printf("Minimum Spanning Weight: %d\n", minWeight);

    return 0;
}