#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "knapsack.h"
#include "knapsackDP.h"
#include "knapsackDP2.h"
#include "subsetSum.h"

int run_knapsack(int argc, char **argv) {
  int v[] = {0, 250, 380, 420, 520};
  int w[] = {0, 1, 2, 4, 3};

  if (argc == 4) {
    int k = atoi(argv[2]);
    int i = atoi(argv[3]);
    if (k < 1 || 4 < k || i < 1 || 5 < i) {
      fprintf(stderr, "k は [1, 4]、 i は [1, 5] の範囲で指定してください。");
      return 1;
    }
    printf("結果：%d\n", knapsack(v, w, k, i));
    return 0;
  }

  if (argc == 3) {
    int n = atoi(argv[2]);
    int *v = (int *)malloc(sizeof(int) * (n + 1));
    int *w = (int *)malloc(sizeof(int) * (n + 1));
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= n; i++) {
      v[i] = rand() % 101;
      w[i] = rand() % 10 + 1;
    }
    printf("容量：%d\n", n * 5);
    clock_t start_clock, end_clock;
    start_clock = clock();
    int i = knapsack(v, w, n, n * 5);
    end_clock = clock();
    printf("結果：%d\n", i);
    printf("実行時間：%f sec.\n",
           (double)(end_clock - start_clock) / CLOCKS_PER_SEC);
    free(v);
    free(w);
    return 0;
  }

  fprintf(stderr, "Usage: main knapsack <k: no. of items> [<i: capacity>]\n");
  return 1;
}

int run_knapsack_dp(int argc, char **argv) {
  int v[] = {0, 250, 380, 420, 520};
  int w[] = {0, 1, 2, 4, 3};

  if (argc == 4) {
    int k = atoi(argv[2]);
    int i = atoi(argv[3]);
    if (k < 1 || 4 < k || i < 1 || 5 < i) {
      fprintf(stderr, "k は [1, 4]、 i は [1, 5] の範囲で指定してください。");
      return 1;
    }
    printf("結果：%d\n", knapsack_dp(v, w, k, i));
    return 0;
  }

  if (argc == 3) {
    int n = atoi(argv[2]);
    int *v = (int *)malloc(sizeof(int) * (n + 1));
    int *w = (int *)malloc(sizeof(int) * (n + 1));
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= n; i++) {
      v[i] = rand() % 101;
      w[i] = rand() % 10 + 1;
    }
    printf("容量：%d\n", n * 5);
    clock_t start_clock, end_clock;
    start_clock = clock();
    int i = knapsack_dp(v, w, n, n * 5);
    end_clock = clock();
    printf("結果：%d\n", i);
    printf("実行時間：%f sec.\n",
           (double)(end_clock - start_clock) / CLOCKS_PER_SEC);
    free(v);
    free(w);
    return 0;
  }

  fprintf(stderr, "Usage: main knapsackDP <k: no. of items> [<i: capacity>]\n");
  return 1;
}

int run_knapsack_dp2(int argc, char **argv) {
  int num = 4;
  int v4[] = {0, 250, 380, 420, 520};
  int v10[] = {0, 250, 380, 420, 520, 640, 740, 800, 950, 1000, 1100};
  int w4[] = {0, 1, 2, 4, 3};
  int w10[] = {0, 1, 2, 4, 3, 2, 5, 6, 7, 3, 1};

  if (argc >= 4) {  
    int k = atoi(argv[2]);
    int i = atoi(argv[3]);
    if (argc == 5) {
      num = atoi(argv[4]);
      if (num != 4 && num != 10) {
        fprintf(stderr, "num は 4 または 10 で指定してください。");
        return 1;
      }
    }
    int *v = (num == 4) ? v4 : v10;
    int *w = (num == 4) ? w4 : w10;
    bool *S = knapsack_dp2(v, w, k, i);
    int total = 0;
    for (int k = 1; k <= num; k++) {
      if (S[k]) {
        total = total + v[k];
        printf("重さ %d 価値 %d\n", w[k], v[k]);
      }
    }
    printf("合計価値 %d\n", total);
    return 0;
  }

  fprintf(stderr, "Usage: knapsackDP2 <k: no. of items> <i: capacity> [<num: 4 or 10>]\n");
  return 1;
}

int run_subset_sum(int argc, char **argv) {
  int set[] = {3, 7, 11, 15};
  int len = 4;

  if (argc == 4) {
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);
    bool *S = subsetSum(set, len, n, k);
    if (S != NULL) {
      printf("部分集合");
      for (int j = 0; j < len; j++) {
        if (S[j]) {
          printf("%d ", set[j]);
        }
      }
    } else {
      printf("条件を満たす部分集合はない．\n");
    }
    return 0;
  }
  fprintf(stderr, "Usage: subsetsum <n> <sum>\n");
  return -1;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: main <algorithm> <args>\n<algorithm>: knapsack, "
                    "knapsackDP, knapsackDP2, subsetSum\n");
    return 1;
  }

  if (strcmp(argv[1], "knapsack") == 0) {
    return run_knapsack(argc, argv);
  } else if (strcmp(argv[1], "knapsackDP") == 0) {
    return run_knapsack_dp(argc, argv);
  } else if (strcmp(argv[1], "knapsackDP2") == 0) {
    return run_knapsack_dp2(argc, argv);
  } else if (strcmp(argv[1], "subsetSum") == 0) {
    return run_subset_sum(argc, argv);
  } else {
    fprintf(stderr, "Usage: main <algorithm> <args>\n<algorithm>: knapsack, "
                    "knapsackDP, knapsackDP2, subsetSum\n");
    return 1;
  }
}
