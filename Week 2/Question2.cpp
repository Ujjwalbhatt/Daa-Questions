/*Given a sorted array of positive integers, design an algorithm and implement it using a program to 
find three indices i, j, k such that arr[i] + arr[j] = arr[k].*/
#include <stdio.h>
#include <stdlib.h>
void func(int arr[], int n){
    int flag = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] == arr[k]){
                    printf(" \n %d,%d,%d", i, j, k);
                    flag++;
                    return;
                }
            }
        }
    }
    if (flag == 0) {
        printf("\nNo sequence found");
    }
}
int main(){
    int n, t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++){
            arr[i] = rand() % 100 + 1;
            printf("%d ", arr[i]);
        }
        func(arr, n);
    }
    return 0;
}
