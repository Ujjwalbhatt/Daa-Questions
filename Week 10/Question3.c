// Given an unsorted array of elements, design an algorithm and implement it using a program to find
// whether majority element exists or not. Also find median of the array. A majority element isan
// element that appears more than n/2 times, where n is the size of array.

#include <stdio.h>
#include <stdlib.h>
int findMajorityElement(int arr[], int n)
{
    int candidate = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
        else if (arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
    return candidate;
    }
    return -1;
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
float findMedian(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
    {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else
    {
        return arr[n / 2];
    }
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int majorityElement = findMajorityElement(arr, n);
    if (majorityElement != -1)
    {
        printf("yes\n%d\n", majorityElement);
       
    }
    else
    {
        printf("Majority element does not exist\n");
    }
    float median = findMedian(arr, n);
    printf("Median of the array: %f\n", median);
    return 0;
}