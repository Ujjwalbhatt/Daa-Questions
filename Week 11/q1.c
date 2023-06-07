#include <stdio.h>
#include <limits.h>
void matrixChainOrder(int dims[], int n)
{
    int m[n][n];
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
           
        }
    }
    printf("\n");
    printf("Minimum Scalar Multiplications: %d\n", m[1][n - 1]);
}
int main()
{
    int dims[] = {5, 28, 47, 80};
    int n = sizeof(dims) / sizeof(dims[0]);
    matrixChainOrder(dims, n);
    return 0;
}