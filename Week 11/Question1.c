// //Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
// matrices together. To find the optimal solution, you need to find the order in which these
// matrices should be multiplied.
//also find the position to divide the matrix into two sub-matrices for minimum cost

// #include <stdio.h>
// #include <limits.h>
// int matrixChainOrder(int p[], int n) {
//     int m[n][n];
//     int i, j, k, L, q;

//     for (i = 1; i < n; i++)
//         m[i][i] = 0;

//     for (L = 2; L < n; L++) {
//         for (i = 1; i < n - L + 1; i++) {
//             j = i + L - 1;
//             m[i][j] = INT_MAX;
//             for (k = i; k <= j - 1; k++) {
//                 q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//                 if (q < m[i][j])
//                     m[i][j] = q;
//             }
//         }
//     }

  



//     return m[1][n - 1];
// }

// int main() {
//     int n, i;
//     scanf("%d", &n);
//     int p[n+1];
//     for (i = 0; i <= n; i++)
//         scanf("%d", &p[i]);

//     printf("Minimum number of operations: %d", matrixChainOrder(p, n+1));
    


//         return 0;
// }


#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

int matrix_chain_order(int p[], int n, int m[][MAX_SIZE], int s[][MAX_SIZE]) {
    int i, j, k, l, q;

    // Initialize the cost matrix
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // Fill in the cost matrix
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n-l+1; i++) {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Return the minimum cost of multiplying the entire sequence of matrices
    return m[1][n];
}

int matrix_split_position(int p[], int n) {
    int i, j, k, l, q, min_cost, min_pos;

    // Initialize the cost matrix
    int m[MAX_SIZE][MAX_SIZE];
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // Fill in the cost matrix
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n-l+1; i++) {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    // Find the position with the minimum cost
    min_cost = INT_MAX;
    for (i = 1; i < n; i++) {
        q = m[1][i] + m[i+1][n];
        if (q < min_cost) {
            min_cost = q;
            min_pos = i;
        }
    }

    // Return the optimal split position
    return min_pos;
}

int main() {
    int p[] = {5, 4, 43,  60};
    int n = sizeof(p)/sizeof(p[0]);

    int m[MAX_SIZE][MAX_SIZE], s[MAX_SIZE][MAX_SIZE];
    int min_cost = matrix_chain_order(p, n-1, m, s);
    int min_pos = matrix_split_position(p, n-1);

    printf("Minimum cost of multiplying the matrices: %d\n", min_cost);
    printf("Optimal split position: %d\n", min_pos);

    return 0;
}