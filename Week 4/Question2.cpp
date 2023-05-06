/*
    Given an unsorted array of integers, design an algorithm and implement it using a program to sort
an array of elements by partitioning the array into two subarrays based on a pivot element such
that one of the sub array holds values smaller than the pivot element while another subarray
holds values greater than the pivot element. Pivot element should be selected randomly from the
array. Your program should also find number of comparisons and swaps required for sorting the
array.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int cmp_count = 0;
int swap_count = 0;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;
    do
    {
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            
        }
    }while(i<j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;

}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the arrays :";
    cin>>n;
    int arr[n];
    cout<<"Enter the element of the arrrays: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i = 0; i<n;i++ ){
        cout<<arr[i]<<" ";
    }
    return 0;
}