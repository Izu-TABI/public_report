#include <stdio.h>
#include <stdlib.h>

int kaijou(int n) {
  if (n != 0) {
    return n * kaijou(n - 1);
  } else {
    return 1;
  }
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("引数が指定されていません.\n");
    return 0;
  }

  int input_n = atoi(argv[1]);
  int ans = 0;

  ans = kaijou(input_n);
  printf("%dの階乗は%dです. \n", input_n, ans);

  return 0;
}
