#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* buf を空白で分割して argv にセットする。
   buf の内容を破壊して各 argv[i] が buf 内のポインタを指す。
   最後に argv[n] = NULL をセットして、引数の個数を返す。 */
int getarg(char *argv[], char *buf) {
  int i = 0;
  char *tok;

  tok = strtok(buf, " ");
  while (tok != NULL && i < 255) {
    argv[i++] = tok;
    tok = strtok(NULL, " ");
  }
  argv[i] = NULL;
  return i;
}

int main() {
  char *argv[256];
  char command[256], line[256];
  int st;
  static char prompt[64] = "> ";

  fprintf(stderr, "%s", prompt);
  while (fgets(line, sizeof(line), stdin) != NULL) {
    // %[^\n]→フォーマット指定子　%[^ここに書かれた文字が区切り文字となる]
    if (sscanf(line, "%[^\n]", command) > 0) {
      getarg(argv, command);
      if (fork() == 0) {
        if (execv(argv[0], argv) < 0) {
          exit(EXIT_FAILURE);
        }

      } else {
        wait(&st);
      }
    }
    fprintf(stderr, "%s", prompt);
  }

  return EXIT_SUCCESS;
}
