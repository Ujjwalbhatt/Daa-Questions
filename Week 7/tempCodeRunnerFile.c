#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
bool visited[MAX_NODES];
int previous[MAX_NODES];

int find_min_distance(int n) {
    int min_index = -1;
    int min_distance = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min_distance) {
            min_distance = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int start, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        previous[i] = -1;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = find_min_distance(n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }
}

void print_path(int dest) {
    if (previous[dest] == -1) {
        printf("%d", dest);
        return;
    }
    print_path(previous[dest]);
    printf(" -> %d", dest);
}

int main() {
    int n, akshay_house, num_friends;

    printf("Enter the number of vertices (including Akshay's house and friends' houses): ");
    scanf("%d", &n);

    printf("Enter the index of Akshay's house (0 to %d): ", n - 1);
    scanf("%d", &akshay_house);

    printf("Enter the number of friends: ");
    scanf("%d", &num_friends);

    int friends[num_friends];
    printf("Enter the indices of friends' houses (0 to %d):\n", n - 1);
    for (int i = 0; i < num_friends; i++) {
        scanf("%d", &friends[i]);
    }
    printf("Enter the adjacency matrix (use 0 for no edge and positive integer for edge weight):\n");
    for (int i = 0; i < n; i++) {
        printf("Enter row %d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    dijkstra(akshay_house, n);
    for (int i = 0; i < num_friends; i++) {
        printf("Shortest path from %d to %d: ", friends[i], akshay_house);
        print_path(friends[i]);
        printf("\nDistance: %d\n", dist[friends[i]]);
    }
    return 0;
}