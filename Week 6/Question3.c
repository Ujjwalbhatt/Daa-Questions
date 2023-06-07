//  Given a directed graph, design an algorithm and implement it using a program to find whether
// cycle exists in the graph or not.
/*
Input: 
5 
0 1 1 0 0
0 0 0 1 1
0 1 0 1 0
0 0 0 0 1
0 0 0 0 0
Output:
No Cycle Exists
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int **adj, bool *visited, bool *recStack, int v, int V) {
    visited[v] = true;
    recStack[v] = true;

    for (int u = 0; u < V; u++) {
        if (adj[v][u]) {
            if (!visited[u] && dfs(adj, visited, recStack, u, V)) {
                return true;
            } else if (recStack[u]) {
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycle(int **adj, int V) {
    bool *visited = (bool *) calloc(V, sizeof(bool));
    bool *recStack = (bool *) calloc(V, sizeof(bool));

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dfs(adj, visited, recStack, v, V)) {
            free(visited);
            free(recStack);
            return true;
        }
    }

    free(visited);
    free(recStack);
    return false;
}

int main() {
    int V;
    scanf("%d", &V);

    int **adj = (int **) malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *) malloc(V * sizeof(int));
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    if (hasCycle(adj, V)) {
        printf("Cycle Exists\n");
    } else {
        printf("No Cycle Exists\n");
    }

    for (int i = 0; i < V; i++) {
        free(adj[i]);
    }
    free(adj);

    return 0;
}




