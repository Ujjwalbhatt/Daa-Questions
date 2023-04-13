// Given an unsorted array of integers, design an algorithm and a program to sort the array using
// insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
// total number of times the array elements are shifted from their place) required for sorting the array.

#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n)
{
    int i, j, key, c = 0, s = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            s++;
        }
        arr[j + 1] = key;
        c++;
    }
    printf("\nComparisons: %d Shifts: %d ", c, s);
}
int main()
{
    int n, t, key;
    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 100 + 1;
            printf("%d ", arr[i]);
        }
        insertionSort(arr, n);
        printf("\nSorted Array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
