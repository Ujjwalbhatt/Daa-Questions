/*
Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(logn), where n is the size of input).
*/

#include <stdio.h> 
#include<stdlib.h>
#include<time.h>
int binarySearch(int arr[], int n, int key){
    int low, mid, high, comp = 0, count = 0;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high){
        if (arr[mid] == key) {
            count++;
            break;
        }
        if (arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        mid = (low + high) / 2;
        comp++;
    }
    if (count > 0){
        printf("present ");
    }
    else{
        printf("not present ");
    }
    printf("%d\n", comp);
}
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}
int main(){
    int n, key,t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    bubbleSort(arr, n);
    scanf("%d", &key);
    binarySearch(arr, n, key);
    }
    return 0;
}
