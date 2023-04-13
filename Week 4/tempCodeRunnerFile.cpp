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
    // randomly select pivot index
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
    cin >> t;
    cout << "Enter the size of the array: ";
    cin >> n;
    while(t--){
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    cout << "\nNumber of comparisons: " << cmp_count << endl;
    cout << "Number of swaps: " << swap_count << endl;
    }
    return 0;
}