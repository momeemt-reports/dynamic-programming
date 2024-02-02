#include "knapsackDP.h"

int knapsack_dp(int v[], int w[], int k, int i) {
  int **dp = (int **)malloc(sizeof(int *) * (k + 1));
  for (int j = 0; j <= k; j++) {
    dp[j] = (int *)malloc(sizeof(int) * (i + 1));
  }
  for (int j = 0; j <= k; j++) {
    for (int l = 0; l <= i; l++) {
      dp[j][l] = 0;
    }
  }
  for (int j = 1; j <= k; j++) {
    for (int l = 1; l <= i; l++) {
      if (w[j] > l) {
        dp[j][l] = dp[j - 1][l];
      } else {
        dp[j][l] = max(dp[j - 1][l], dp[j - 1][l - w[j]] + v[j]);
      }
    }
  }
  int result = dp[k][i];
  for (int j = 0; j <= k; j++) {
    free(dp[j]);
  }
  free(dp);
  return result;
}
