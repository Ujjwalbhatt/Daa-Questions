/*Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],. ,arr[2k ] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): */
#include <stdio.h>
#include <stdlib.h>
void func(int arr[], int n, int key)
{
    // 1 2 3 4 5 6 7 8
    int jump = 2,flag=0,low=0;
 for(int i = 0;i<n;i=i+jump){
    if(arr[i]==key){
        flag = 1;
        break;
    }
    if(arr[i]<key){
        low=i;
    }
    if(arr[i]>key){
        break;
    }
 }  
 for(int i = low;i<n;i++){
    if(arr[i] == key){
        flag =1;
        break;
    }

 }  
 if(flag == 1){
    printf("Element found");
 }
 else{
        printf("Element not found");
 }
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
        scanf("%d", &key);
        func(arr, n, key);
    }
    return 0;
}
