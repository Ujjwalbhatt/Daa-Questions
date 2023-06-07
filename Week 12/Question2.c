#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}
void knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
  int selectedItems[n];
    int res = K[n][W];
    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
        {
            continue;
        }
        selectedItems[i - 1] = 1;
        res -= val[i - 1];
        w -= wt[i - 1];
    }
    printf("Selected items:\n");
    for (i = 0; i < n; i++)
    {
        if (selectedItems[i])
            printf("Item %d\n", i + 1);
    }
}
int main()
{
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++)
        
        {
            printf("Item %d:\n", i + 1);
            scanf("%d", &val[i]);
            scanf("%d", &wt[i]);
        }
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    knapsack(W, wt, val, n);
    return 0;
}