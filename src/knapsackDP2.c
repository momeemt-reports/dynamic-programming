#include "knapsackDP2.h"

bool* knapsack_dp2(int v[], int w[], int n, int W) {
    int **dp = (int **)malloc(sizeof(int*) * (n + 1));
    bool **keep = (bool **)malloc(sizeof(bool*) * (n + 1));
    bool *selected = (bool *)malloc(sizeof(bool) * (n + 1));

    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (W + 1));
        keep[i] = (bool *)malloc(sizeof(bool) * (W + 1));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i] <= j) {
                if (v[i] + dp[i - 1][j - w[i]] > dp[i - 1][j]) {
                    dp[i][j] = v[i] + dp[i - 1][j - w[i]];
                    keep[i][j] = true;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    keep[i][j] = false;
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                keep[i][j] = false;
            }
        }
    }

    for (int i = n, j = W; i > 0; i--) {
        if (keep[i][j]) {
            selected[i] = true;
            j = j - w[i];
        } else {
            selected[i] = false;
        }
    }

    for (int i = 0; i <= n; i++) {
        free(dp[i]);
        free(keep[i]);
    }
    free(dp);
    free(keep);

    return selected;
}
