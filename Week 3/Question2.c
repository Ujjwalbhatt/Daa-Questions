// //Given an unsorted array of integers, design an algorithm and implement a program to sort this
// array using selection sort. Your program should also find number of comparisons and number of
// swaps required.

#include <stdio.h>
#include <stdlib.h>
void selectionSort(int arr[], int n)
{
    int i, j, min, c = 0, s = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            c++;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        s++;
    }
    printf("\nComparisons: %d Swaps: %d ", c, s);
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
        selectionSort(arr, n);
        printf("\nSorted Array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}
