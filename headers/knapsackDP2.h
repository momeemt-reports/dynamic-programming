#ifndef KNAPSACKDP2_H
#define KNAPSACKDP2_H

#include <stdbool.h>
#include <stdlib.h>

int** makeIntMatrix(int rows, int cols);
bool** makeBoolMatrix(int rows, int cols);
bool* knapsack_dp2(int v[], int w[], int n, int C);

#endif // KNAPSACKDP2_H
