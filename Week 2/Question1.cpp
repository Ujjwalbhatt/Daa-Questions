/*
1.Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
*/

// #include <stdio.h> 
// #include<stdlib.h>
// void func(int arr[], int n, int key){
//     int count = 0;
//     for (int i = 0; i < n; i++){
//         if (arr[i] == key){
//             count++;
//         }
//     }
//     if(count==0){
//         printf("key not found");
//     }
//     else{
//     printf("%d-%d", key, count);
//     }
// }
// int main()
// {
//     int n,t;
//     int key;
//     scanf("%d", &t);
//     for (int k = 0; k < t; k++){
//     scanf("%d", &n);
//     int arr[n];
//     for (int i = 0; i < n; i++){
//         arr[i] = rand() % 100 + 1;
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     scanf("%d", &key);
//     func(arr, n, key);
//     }
//     return 0;
// }

// // Path: Week 2\Question1.c
// // C++ program to count occurrences of an element
#include <bits/stdc++.h>
using namespace std;
 
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    int low = l;
    int high = r;
    int mid;
    while(l<=r){
     mid = (low+high)/ 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x)
        low = mid + 1;
    else
    high = mid-1;
    }
    return -1;
}
 
// Returns number of times x occurs in arr[0..n-1]
int countOccurrences(int arr[], int n, int x)
{
    int ind = binarySearch(arr, 0, n - 1, x);

    // If element is not present
    if (ind == -1)
        return 0;
 
    // Count elements on left side.
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;
 
    // Count elements on right side.
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;
 
    return count;
}
 
// Driver code
int main()
{
    int arr[] = { 1, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << countOccurrences(arr, n, x);
    return 0;
}