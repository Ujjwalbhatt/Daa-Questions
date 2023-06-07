/*
Given a graph, Design an algorithm and implement it using a program to implement Floyd Warshall all pair shortest path algorithm.
Input Format:
The first line of input takes number of vertices in the graph.
Input will be the graph in the form of adjacency matrix or adjacency list. If a direct edge is not
present between any pair of vertex (u,v), then this entry is shown as AdjM[u,v] = INF.
Output Format:
Output will be shortest distance matrix in the form of V X V matrix, where each entry (u,v)
represents shortest distance between vertex u and vertex v.
Sample I/O Problem I:
Input: 
3
0 10 5 5 INF
INF 0 5 5 5
INF INF 0 INF
INF INF INF 0 20
INF INF INF 5 0
Output:
Shortest Distance Matrix:
0 10 15 5 15
INF 0 5 5 5
INF INF 0 15 10
INF INF INF 0 20
INF INF INF 5 0
*/ 

// Floyd-Warshall Algorithm in C

#include <stdio.h>

// defining the number of vertices
#define nV 4

#define INF 999

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
   for (j = 0; j < nV; j++)
   matrix[i][j] = graph[i][j];
  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
     printMatrix(matrix);
     printf("\n---------------------\n");
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[nV][nV] = {
            {0,3,INF,7},
            {8,0,2,INF},
            {5,INF,0,1},
            {2,INF,INF,0}
             };

  floydWarshall(graph);
}