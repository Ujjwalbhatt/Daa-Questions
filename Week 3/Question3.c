// //Given an unsorted array of positive integers, design an algorithm and implement it using a program
// to find whether there are any duplicate elements in the array or not. (use merge sorting) (Time Complexity
// Time complelxity = O(n log n)) 
//while sorting check for duplicate
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int left_len, int right_len) {
    int i = 0, j = 0, k = 0;

    while (i < left_len && j < right_len) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else if (left[i] > right[j]) {
            arr[k++] = right[j++];
        } else {
            printf("Duplicate element found: %d\n", left[i]);
            i++;
            k++;
        }
    }

    while (i < left_len) {
        arr[k++] = left[i++];
    }

    while (j < right_len) {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int len) {
    if (len > 1) {
        int mid = len / 2;
        int *left = (int *) malloc(mid * sizeof(int));
        int *right = (int *) malloc((len - mid) * sizeof(int));

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }

        for (int i = mid; i < len; i++) {
            right[i - mid] = arr[i];
        }

        merge_sort(left, mid);
        merge_sort(right, len - mid);
        merge(arr, left, right, mid, len - mid);

        free(left);
        free(right);
    }
}

int main() {
    int t,k,n;
     scanf("%d", &t);
    for (int k = 0; k < t; k++){
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int len = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, len);
    
    }

    return 0;
}







