/*Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not. (Hint: use BFS)*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];

typedef struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool is_empty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        return;
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (is_empty(q)) {
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

bool is_bipartite(int start, int n) {
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    Queue* q = create_queue();
    enqueue(q, start);
    color[start] = 1;

    while (!is_empty(q)) {
        int current = dequeue(q);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && color[i] == -1) {
                color[i] = 1 - color[current];
                enqueue(q, i);
            } else if (graph[current][i] && color[i] == color[current]) {
                return false;
            }
        }
    }

    return true;
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

    bool result = is_bipartite(0, n);

    if (result) {
        printf("The graph is bipartite.\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

    return 0;
}
