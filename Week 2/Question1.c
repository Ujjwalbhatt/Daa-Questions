// Q4.Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not .If present, then also find the number of copies of given key.SOURCE CODE

#include <stdio.h> 
#include<stdlib.h>
void func(int arr[], int n, int key){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == key){
            count++;
        }
    }
    if(count==0){
        printf("key not found");
    }
    else{
    printf("%d-%d", key, count);
    }
}
int main()
{
    int n,t;
    int key;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    scanf("%d", &key);
    func(arr, n, key);
    }
    return 0;
}
