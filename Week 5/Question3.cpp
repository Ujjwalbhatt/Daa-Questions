// You have been given two sorted integer arrays of size m and n. Design an algorithm and implement
// it using a program to find list of elements which are common to both. (Time Complexity = 
// O(m+n))

#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the size of the first array: ";
    cin >> m;
    int arr1[m];
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the size of the second array: ";
    cin >> n;
    int arr2[n];
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    int i = 0, j = 0;
    cout << "The common elements are: ";
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << endl;
    return 0;
}