/*
Given a directed graph with two vertices ( source and destination). Design an algorithm and
implement it using a program to find the weight of the shortest path from source to destination
with exactly k edges on the path.
*/

#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
int main() {
  int source, destination, k;

  printf("Enter the source vertex: ");
  scanf("%d", &source);

  printf("Enter the destination vertex: ");
  scanf("%d", &destination);

  printf("Enter the number of edges: ");
  scanf("%d", &k);

  int graph[4][4] = {
    {0, 10, 3, 2},
    {999999999, 0, 999999999, 7},
    {999999999, 999999999, 0, 6},
    {999999999, 999999999, 999999999, 0}
  };

  int dp[4][k + 1];

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = 999999999;
    }
  }

  dp[source][0] = 0;

  for (int j = 1; j <= k; j++) {
    for (int i = 0; i < 4; i++) {
      for (int to = 0; to < 4; to++) {
        if (graph[i][to] != 999999999) {
          dp[j][to] = min(dp[j][to], dp[j - 1][i] + graph[i][to]);
        }
      }
    }
  }

  int weight = dp[k][destination];

  printf("The weight of the shortest path from %d to %d with exactly %d edges is %d\n", source, destination, k, weight);

  return 0;
}