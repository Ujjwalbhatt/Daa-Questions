// Given an unsorted array of integers, design an algorithm and implement it using a program to find 
// whether two elements exist such that their sum is equal to the given key element. (Time
// Complexity = O(n log n))

#include <iostream>
using namespace std;

int main()
{
    int n, key;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key element: ";
    cin >> key;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == key)
        {
            cout << "The elements are " << arr[i] << " and " << arr[j] << endl;
            return 0;
        }
        else if (arr[i] + arr[j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "No such elements exist." << endl;
    return 0;
}
