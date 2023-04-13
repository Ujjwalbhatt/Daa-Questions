#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000 // Define the size of the array

//Sort the array using bubble sort

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}


int main() {
    int arr[ARRAY_SIZE];
    int x = 5234; // Generate a random number between 0 and 99
    clock_t start, end;
    double cpu_time_used;

    // Initialize the array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }


    // Sort the array using quicksort
    bubble_sort(arr, ARRAY_SIZE);

    start = clock(); // Start the timer
    // Perform binary search on the array
    int result = binary_search(arr, ARRAY_SIZE, x);

    end = clock(); // End the timer

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000000; // Calculate the time taken in microseconds

    if (result == -1) {
        printf("%d not found in the array.\n", x);
    } else {
        printf("%d found at index %d in the array.\n", x, result);
    }

    printf("Time taken by binary search: %f microseconds\n", cpu_time_used);

    return 0;
}
