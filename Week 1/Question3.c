#include <stdio.h>
#include <stdlib.h>
void func(int arr[], int n, int key)
{
    int c = 0, i;
    for (i = 0; i < n; i++)
    {
        if (arr[2 ^ i] == key)
        {
            c++;
            break;
        }
        if (arr[2 ^ (i + 1) > key])
        {
            for (int j = 2 ^ (i + 1); j < n; j++)
            {
                if (arr[j] == key)
                {
                    c++;
                    break;
                }
            }
        }
    }
    if (c > 1)
    {
        printf("present\n");
    }
    else
    {
        printf("not present\n\n");
    }
}
int main()
{
    int n, t, key;
    scanf("%d", &t);
    for (int k = 0; k < t; k++)
    {
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 100 + 1;
            printf("%d ", arr[i]);
        }
        scanf("%d", &key);
        func(arr, n, key);
    }
    return 0;
}
