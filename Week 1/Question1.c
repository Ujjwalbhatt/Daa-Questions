#include <stdio.h>
#include <stdlib.h> 
#include<time.h> 
void func(int arr[],int n,int key){
    int c = 0, i;
    for (i = 0; i < n; i++){
        if (arr[i] == key){
            c++;
            break;
        }
    }
    if (c > 0){
        printf("present ");
        printf("%d", i + 1);
    }
    else{
        printf("not present ");
        printf("%d", i);
    }
}
int main(){
    int n, key,t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100 ;
        printf("%d ", arr[i]);
    }
    scanf("%d", &key);
    func(arr, n, key);
    }
    return 0;
} 
