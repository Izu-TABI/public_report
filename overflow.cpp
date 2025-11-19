#include <stdio.h>
int main() {
  int a = 0;
  while (1) {
    // 初めは1000を足していき，時間短縮
    a += 1000;
    if (a < 0) {
      a -= 1000;
      while (1) {
        a += 1;
        // 足していって負の値になる→オーバーフローしている
        // 逆に，減算していく場合は比較演算子を逆にすることで対応する
        if (a < 0) {
          printf("\n%dでオーバーフローしました．\n\n", a - 1);
          break;
        }
      }
      break;
    }
  }
  return 0;
}
