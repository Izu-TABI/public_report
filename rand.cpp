#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
  int rand_rec[10] = {0};

  for (int i = 0; i < 100; i++) {
    int num = rand() % 10 + 1;

    rand_rec[num - 1] += 1;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d: %d\n", i + 1, rand_rec[i]);
  }

  return 0;
}
