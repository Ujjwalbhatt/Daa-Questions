/*
After end term examination, Akshay wants to party with his friends. All his friends are living aspaying guest and it has been decided to first gather at Akshay’s house and then move towards party location. The problem is that no one knows the exact address of his house in the city. Akshay as a computer science wizard knows how to apply his theory subjects in his real life and came up with an amazing idea to help his friends. He draws a graph by looking in to location of his house and his friends’ location (as a node in the graph) on a map. He wishes to find out shortest distance and path covering that distance from each of his friend’s location to his house and then WhatsApp them this path so that they can reach his house in minimum time. Akshay has developed the program that implements bellmondford algorithm but not sure about correctness of results. Can you also implement the same algorithm and verify the correctness of Akshay’s results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)
take input from user like
Input: 
5 
0 4 1 0 0
0 0 0 0 4 
0 2 0 4 0
0 0 0 0 4 
0 0 0 0 0
Output:
1 : 0
2 3 1 : 3
3 1 : 1
4 3 1 : 3
5 2 3 1 : 7
1
*/ 
#include <stdio.h>

#define INF 99999999

void bellman_ford(int n, int graph[n][n], int source) {
  int distances[n];
  for (int i = 0; i < n; i++) {
    distances[i] = INF;
  }
  distances[source] = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
          distances[v] = distances[u] + graph[u][v];
        }
      }
    }
  }

  for (int u = 0; u < n; u++) {
    for (int v = 0; v < n; v++) {
      if (graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
        printf("Negative weight cycle detected\n");
        return;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d : %d\n", i + 1, distances[i]);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  int source;
  scanf("%d", &source);

  bellman_ford(n, graph, source);

  return 0;
}


