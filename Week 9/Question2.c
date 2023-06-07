// //Given a knapsack of maximum capacity w. N items are provided, each having its own value and
// weight. You have to Design an algorithm and implement it using a program to find the list of the
// selected items such that the final selected content has weight w and has maximum value. You can
// take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry
// only a fraction xi of item i, where 0 ≤xi≤ 1
/*
Input: 
6
6 10 3 5 1 3
6 2 1 8 3 5 
16
Output:
Maximum value : 22.33
item-weight
5-1
6-3 
4-5 
1-6 
3-1 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Item {
    int value;
    int weight;
} Item;
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;
    return (ratioA < ratioB) - (ratioA > ratioB);
}
double fractional_knapsack(Item items[], int n, int w) {
    qsort(items, n, sizeof(Item), compare);

    double max_value = 0.0;
    int remaining_weight = w;

    for (int i = n - 1; i >= 0 && remaining_weight > 0; i--) {
        if (items[i].weight <= remaining_weight) {
            max_value += items[i].value;
            remaining_weight -= items[i].weight;
        } else {
            double fraction = (double)remaining_weight / items[i].weight;
            max_value += items[i].value * fraction;
            remaining_weight = 0;
        }
    }
    return max_value;
}
int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    int w;
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &w);
    double max_value = fractional_knapsack(items, n, w);
    printf("Maximum value: %.2f\n", max_value);
    return 0;
}
