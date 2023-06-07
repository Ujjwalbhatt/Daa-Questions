//Maximum spannign tree

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

int compareEdges(const void *a, const void *b) {
    return ((Edge *)b)->weight - ((Edge *)a)->weight;
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

int kruskalMaxSpanningWeight(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(Edge), compareEdges);

    int *parent = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i)
        parent[i] = -1;

    int maxWeight = 0;
    for (int i = 0; i < E; ++i) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        if (x != y) {
            maxWeight += edges[i].weight;
            Union(parent, x, y);
        }
    }

    free(parent);
    return maxWeight;
}

int main() {
    int V;
    scanf("%d", &V);

    int adjMatrix[V][V];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    Edge edges[V * V];
    int edgeCount = 0;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            if (adjMatrix[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = adjMatrix[i][j];
                edgeCount++;
            }
        }
    }

    int maxSpanningWeight = kruskalMaxSpanningWeight(edges, V, edgeCount);
    printf("Maximum Spanning Weight: %d\n", maxSpanningWeight);

    return 0;
}
