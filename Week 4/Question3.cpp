/*
Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/

#include <iostream>
  
   

using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[high]);
    int i = low;
    for (int j = low; j < high; j++) {
         
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
    cin >> t;
    while(t--){
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    int k;
    cin >> k;
    quickSort(arr, 0, n - 1);
    cout << k << "th smallest element: " << arr[k - 1] << endl;
    cout << k << "th largest element: " << arr[n - k] << endl;
    }
    return 0;
}
