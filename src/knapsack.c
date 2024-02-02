#include "knapsack.h"

int knapsack(int v[], int w[], int k, int i) {
  if (k == 0)
    return 0;
  if (w[k] > i)
    return knapsack(v, w, k - 1, i);
  return max(knapsack(v, w, k - 1, i), knapsack(v, w, k - 1, i - w[k]) + v[k]);
}
