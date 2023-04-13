#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

void merge(int arr[], int l, int m, int r, int &cmp_count, int &inv_count)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        cmp_count++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inv_count += n1 - i;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int &cmp_count, int &inv_count)
{
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, cmp_count, inv_count);
    mergeSort(arr, m + 1, r, cmp_count, inv_count);
    merge(arr, l, m, r, cmp_count, inv_count);
}

int main()
{
    int n;
    int t;
    double time_taken;
    cin >> t;
    while(t--){

    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++){
    //genrate random numbers
        arr[i] = rand() % 1000;
    }

    int cmp_count = 0, inv_count = 0;

    clock_t start = clock();
    mergeSort(arr, 0, n - 1, cmp_count, inv_count);
    clock_t end = clock();

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    
   
    cout << "\nNumber of comparisons: " << cmp_count << endl;
    cout << "Number of inversions: " << inv_count << endl;
    cout << "Time taken in ms:  " << time_taken * 1000000 << endl;
    }

    return 0;
}