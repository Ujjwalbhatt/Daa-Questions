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
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    swap_count++;  
}
int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivotValue = arr[pivotIndex];
    
    swap(arr[pivotIndex], arr[high]);
    int i = low;
    for (int j = low; j < high; j++) {
        cmp_count++;   
        if (arr[j] < pivotValue) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
       
        int pivotIndex = partition(arr, low, high);
      
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
    int n;
    int t;
    double time;

    cin >> t;
    cout << "Enter the size of the array: ";
    cin >> n;
    while(t--){
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    arr[i] = rand() % 1000;
    clock_t start = clock();    
    quickSort(arr, 0, n - 1);
    clock_t end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Number of comparisons: " << cmp_count << endl;
    cout << "Number of swaps: " << swap_count ;
    cout << "Time taken in microseconds : " <<  time*1000000 << endl;
    }
    return 0;
}