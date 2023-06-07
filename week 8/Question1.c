//Implement problem using Kruskal's algorithm tak input from user
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

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

int kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0, i = 0;

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    int* parent = (int*) malloc(V * sizeof(int));
    for (int v = 0; v < V; ++v)
        parent[v] = -1;

    while (e < V - 1) {
        Edge nextEdge = graph->edges[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(parent, x, y);
        }
    }

    int minWeight = 0;
    for (i = 0; i < e; ++i)
        minWeight += result[i].weight;

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
    graph->edges = (Edge*) malloc(E * sizeof(Edge));

    printf("Enter the source, destination and weight for each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    int minWeight = kruskalMST(graph);
    printf("Minimum Spanning Weight: %d\n", minWeight);

    return 0;
}




