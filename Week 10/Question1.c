#include <stdio.h>
#include<stdlib.h>
struct Activity
{
    int start, finish;
};
int compareActivities(const void *a, const void *b)
{
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}
void selectActivities(struct Activity activities[], int n)
{
    qsort(activities, n, sizeof(struct Activity), compareActivities);
    int i = 0, j;
    printf("Selected activity: (%d, %d)\n", activities[i].start, activities[i].finish);
    for (j = 1; j < n; j++)
    {
        if (activities[j].start >= activities[i].finish)
        {
            printf("Selected activity: (%d, %d)\n", activities[j].start,
                   activities[j].finish);
            i = j;
        }
    }
}
int main()
{
    struct Activity activities[] = {
        {1, 5}, {1, 2}, {6, 7}, {1, 5}, {6, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);
    printf("Activities:\n");
    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d)\n", activities[i].start, activities[i].finish);
    }
    selectActivities(activities, n);
    return 0;
}