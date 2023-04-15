// //Given an unsorted array of positive integers, design an algorithm and implement it using a program
// to find whether there are any duplicate elements in the array or not. (use merge sorting) (Time Complexity
// Time complelxity = O(n log n))
// while sorting check for duplicate
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int b[100];
    int k = low;
    while(i<=mid &&  j<=high){
        if(arr[i]<arr[j]){
            b[k] = arr[i];
            i++;
            k++;
        }
        else{
            b[k] = arr[j];
            j++;
            k++;
        }
    
    }

    while(i<=mid){
        b[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k] = arr[i];
        j++;
        k++;
    }
    for(int i = low ; i<=high; i++){
        arr[i] = b[i];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
    int t, k, n;
    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int len = sizeof(arr) / sizeof(arr[0]);

        merge_sort(arr, 0,n-1);
         for (int i = 0; i < n; i++)
        {
            printf("%d", arr[i]);
        }
    }

    return 0;
}
