#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int capacity, const int weights[], const int values[], int n) {
    int **dp = malloc((size_t)(n + 1) * sizeof(int *));
    if (dp == NULL) return -1;

    for (int i = 0; i <= n; i++) {
        dp[i] = calloc((size_t)(capacity + 1), sizeof(int));
        if (dp[i] == NULL) {
            for (int j = 0; j < i; j++) free(dp[j]);
            free(dp);
            return -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                                dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int result = dp[n][capacity];

    for (int i = 0; i <= n; i++) free(dp[i]);
    free(dp);

    return result;
}

int main(void) {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }

    int *weights = malloc((size_t)n * sizeof(int));
    int *values = malloc((size_t)n * sizeof(int));

    if (weights == NULL || values == NULL) {
        printf("Memory allocation failed.\n");
        free(weights);
        free(values);
        return 1;
    }

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &values[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    if (capacity < 0) {
        printf("Invalid capacity.\n");
        free(weights);
        free(values);
        return 1;
    }

    int result = knapsack(capacity, weights, values, n);
    printf("\nMaximum value = %d\n", result);

    free(weights);
    free(values);
    return 0;
}
