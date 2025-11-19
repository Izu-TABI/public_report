#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct S_LIST {
  int s_data;
  struct S_LIST *ptr;
} S_LIST;

int main() {
  S_LIST youso[10];
  S_LIST *curr, *head, *w_ptr;
  curr = head = w_ptr = youso;

  srand((unsigned)time(NULL));

  for (int i = 0; i < 10; i++) {
    w_ptr->s_data = rand() % 100;
    curr = w_ptr;
    curr->ptr = ++w_ptr;
  }

  curr->ptr = NULL;

  curr = head;
  printf("ソート前:\n");
  while (curr) {
    printf("%d\n", curr->s_data);
    curr = curr->ptr;
  }
  printf("\n\n");

  for (int i = 0; i < 9; i++) {
    curr = head;
    S_LIST *pre_el = NULL;
    for (int j = 0; j < 9; j++) {
      /* curr が NULL の場合はこれ以上処理できない */
      if (curr == NULL) {
        printf("i: %d j: %d (curr is NULL)\n\n", i, j);
        break;
      }

      S_LIST *next_el = curr->ptr; // 次の要素のポインタをコピー

      if (next_el == NULL) {
        printf("i: %d j: %d, data: %d(next_el is NULL)\n\n", i, j,
               curr->s_data);
        break;
      }

      int current_data = curr->s_data;
      int next_data = next_el->s_data;

      if (current_data > next_data) {
        /* 隣接ノードを入れ替える: next_el を curr の前に移動 */
        S_LIST *tmp_ptr = next_el->ptr;
        next_el->ptr = curr;
        curr->ptr = tmp_ptr;

        if (pre_el != NULL)
          pre_el->ptr = next_el; /* 前ノードの ptr を next_el に更新 */
        else
          head =
              next_el; /* ひとつ前の要素がNULL→currは最初の要素を扱っているため
                          head を更新 */

        pre_el = next_el;
      } else {
        pre_el = curr;
        curr = curr->ptr;
      }
    }
  }

  printf("ソート後: \n");

  curr = head;
  while (curr) {
    printf("%d\n", curr->s_data);
    curr = curr->ptr;
  }

  return 0;
}
