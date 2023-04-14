// Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
// implement it using a program to find which alphabet has maximum number of occurrences and
// print it. (Time Complexity = O(n)) (Hint: Use counting sort)
//Using count sort
#include <iostream>
using namespace std;

int main()
{
    int n,t;
    cin>>t;
    while(t--){
    cin >> n;
    char arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count[26] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - 'a']++;
    }
    int max = 0;
    char maxChar;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            maxChar = i + 'a';
        }
    }
    cout << "The maximum occuring character is " << maxChar << " with " << max << " occurences." << endl;
    }
    return 0;
}

