/*
After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards party 
location. The problem is that no one knows the exact address of his house in the city. Akshay as a 
computer science wizard knows how to apply his theory subjects in his real life and came up with 
an amazing idea to help his friends. He draws a graph by looking in to location of his house and 
his friends’ location (as a node in the graph) on a map. He wishes to find out shortest distance and 
path covering that distance from each of his friend’s location to his house and then whatsapp them 
this path so that they can reach his house in minimum time. Akshay has developed the program 
that implements Dijkstra’s algorithm but not sure about correctness of results. Can you also 
implement the same algorithm and verify the correctness of Akshay’s results? (Hint: Print shortest 
path and distance from friends’ location to Akshay’s house)
*/

#include <stdio.h>
#include<algorithm>
#define INF 99999999

void dijkstra(int graph[10][10], int n, int start) {
  int dist[10];
  int visited[10];
  int i, j, u, v;

  for (i = 0; i < n; i++) {
    dist[i] = INF;
    visited[i] = 0;
  }

  dist[start] = 0;

  while (1) {
    u = -1;
    for (i = 0; i < n; i++) {
      if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
        u = i;
      }
    }

    if (u == -1) {
      break;
    }

    visited[u] = 1;

    for (v = 0; v < n; v++) {
      if (graph[u][v] != 0) {
        dist[v] = min(dist[v], dist[u] + graph[u][v]);
      }
    }
  }

  for (i = 0; i < n; i++) {
    printf("The shortest distance from %d to %d is %d\n", start, i, dist[i]);
  }
}

int main() {
  int graph[10][10] = {{0, 9, 7, 0, 0, 0, 0, 0, 0, 0},
                       {9, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                       {7, 0, 0, 0, 4, 0, 0, 0, 0, 0},
                       {0, 3, 0, 0, 0, 2, 0, 0, 0, 0},
                       {0, 0, 4, 0, 0, 0, 5, 0, 0, 0},
                       {0, 0, 0, 2, 0, 0, 0, 9, 0, 0},
                       {0, 0, 0, 0, 5, 0, 0, 0, 7, 0},
                       {0, 0, 0, 0, 0, 9, 0, 0, 0, 8},
                       {0, 0, 0, 0, 0, 0, 7, 0, 8, 0}};

  int start = 0;

  dijkstra(graph, 10, start);

  return 0;
}
