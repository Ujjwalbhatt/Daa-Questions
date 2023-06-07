/*Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)*/


#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

void dfs(int node, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

bool path_exists(int start, int end, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    dfs(start, n);
    return visited[end];
}

int main() {
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start_vertex, end_vertex;

    printf("Enter the start vertex: ");
    scanf("%d", &start_vertex);

    printf("Enter the end vertex: ");
    scanf("%d", &end_vertex);

    bool result = path_exists(start_vertex, end_vertex, n);

    if (result) {
        printf("Path exists between vertices %d and %d\n", start_vertex, end_vertex);
    } else {
        printf("Path does not exist between vertices %d and %d\n", start_vertex, end_vertex);
    }

    return 0;
}






                        



