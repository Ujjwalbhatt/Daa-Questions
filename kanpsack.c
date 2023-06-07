// // Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. You have to Design an algorithm and implement it using a program to find the list of the
// selected items such that the final selected content has weight w and has maximum value. You can
// take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
// only a fraction xi of item i, where 0 ≤xi≤ 1
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int dp[n+1][W+1];
 
    // Build the table in bottom-up manner
    for (i = 0; i <= n; i++) {  
        for (w = 0; w <= W; w++) {
            // Base case: no items or no capacity
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            // If the weight of the current item is less than
            // or equal to the remaining capacity, consider including it
            else if (wt[i-1] <= w)
                // Choose the maximum value by including or excluding the item
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                // Item cannot be included
                dp[i][w] = dp[i-1][w];
        }
    }

    // The maximum value will be at the bottom-right corner of the table
    return dp[n][W];
}

int main() {
    int n, W;
    scanf("%d", &n); // Number of items
    scanf("%d", &W); // Maximum capacity of the knapsack

    int val[n], wt[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]); // Values of the items

    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]); // Weights of the items


    // Call the knapsack function
    int max_value = knapsack(W, wt, val, n);
    printf("%d\n", max_value);

    return 0;
}