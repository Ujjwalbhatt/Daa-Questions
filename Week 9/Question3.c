#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int min_computation_cost(int arr[], int n) {
    int total_cost = 0;

    while (n > 1) {
        qsort(arr, n, sizeof(int), compare);

        int temp = arr[0] + arr[1];
        total_cost += temp;

        for (int i = 2; i < n; i++) {
            arr[i - 1] = arr[i];
        }

        arr[n - 2] = temp;
        n--;
    }

    return total_cost;
}

int main() {
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the file sizes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int cost = min_computation_cost(arr, n);
    printf("Minimum computation cost: %d\n", cost);

    return 0;
}
