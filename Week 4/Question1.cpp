#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

void printArray(int *arr, int size)
{
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void merge(int *arr, int low, int mid, int high, int &cmp_count, int &inv_count)
{
    int b[100],i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]) {
            b[k] = arr[i];
            i++;
            k++;
        }  
        else{
            b[k] = arr[j];
            j++;
            k++;
        }  

        

    }
    while (i<=mid)  
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k] = arr[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++){
        cout<<b[i]<<" ";
        arr[i] = b[i];
    }
    cmp_count++;
    cout<<endl;
}

   
void mergeSort(int *arr, int low, int high, int &cmp_count, int &inv_count)
{
    int mid;
    if (low < high){
                                    
            mid=(high+low)/2;
            mergeSort(arr,low,mid,cmp_count,inv_count);
            mergeSort(arr,mid+1,high,cmp_count,inv_count);
            merge(arr,low,mid,high,cmp_count,inv_count);
    }   
}


int main()
{
    int n;
    int cmp_count=0,inv_count=0;
    cout<<"Enter the size of the arrays: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1,cmp_count,inv_count);
    cout<<"Sorted array: ";
    printArray(arr,n);
    return 0;
}




