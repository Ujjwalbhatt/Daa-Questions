// Q6.Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.SOURCE CODE

#include <stdio.h>
#include <stdlib.h>
void diff(int arr[], int n, int key)
{
    int count = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] - arr[i] == key || arr[i] - arr[j] == key)
            {
                count++;
            }
        }
    }
    if(count==0){
        printf("Not Present");
    }
    else{
        printf("Present %d", count);
    }
}
int main()
{
    double ts = 0.0;
    int n, key,t;
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
    diff(arr, n, key);  
    }
    return 0;
}
