#include <stdio.h>
#include "subsetSum.h"
#include <string.h>

/*
 * set[]: 正の整数の集合
 * n:     対象とする要素数
 * sum:   部分和
 */
bool* subsetSum(int* set, int len, int n, int sum) {
    bool* S  = (bool*)malloc(sizeof(bool) * len);

    bool dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < set[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    if (!dp[n][sum]) {
        free(S);
        return NULL;
    }

    for (int i = n; i > 0; i--) {
        if (dp[i - 1][sum]) {
            S[i - 1] = false;
        } else if (dp[i - 1][sum - set[i - 1]]) {
            S[i - 1] = true;
            sum -= set[i - 1];
        }
    }

    return S;
}
