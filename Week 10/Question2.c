// Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
// deadline associated with it. You have to design an algorithm and implement it using a program to
// find maximum number of tasks that can be completed without crossing their deadlines and also
// find list of selected tasks


#include <stdio.h>
#include <stdlib.h>
typedef struct Task {
    int id;
    int deadline;
    int time;
} Task;

int compare(const void *a, const void *b) {
    Task *taskA = (Task *)a;
    Task *taskB = (Task *)b;
    return (taskA->deadline > taskB->deadline) - (taskA->deadline < taskB->deadline);
}

void task_scheduling(Task tasks[], int n) {
    qsort(tasks, n, sizeof(Task), compare);

    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        if (tasks[i].deadline > max_deadline) {
            max_deadline = tasks[i].deadline;
        }
    }

    int slots[max_deadline];
    for (int i = 0; i < max_deadline; i++) {
        slots[i] = 0;
    }

    int total_time = 0;
    for (int i = 0; i < n; i++) {
        int deadline = tasks[i].deadline;
        while (deadline > 0 && slots[deadline - 1] != 0) {
            deadline--;
        }

        if (deadline > 0) {
            slots[deadline - 1] = tasks[i].id;
            total_time += tasks[i].time;
        }
    }

    printf("Maximum number of tasks: %d\n", max_deadline);
    printf("List of selected tasks:\n");
    for (int i = 0; i < max_deadline; i++) {
        if (slots[i] != 0) {
            printf("%d ", slots[i]);
        }
    }
    printf("\n");
    printf("Total time: %d\n", total_time);
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];
    printf("Enter the deadlines and times of the tasks:\n");
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        scanf("%d %d", &tasks[i].deadline, &tasks[i].time);
    }

    task_scheduling(tasks, n);
}
//Input :  5
// 2 5
// 1 4
// 2 3
// 1 2
// 3 1
// Output :
// Maximum number of tasks : 3

//11 first
//12 first,second,third