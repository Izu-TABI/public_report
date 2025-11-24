#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
  // envpという引数は，親プロセス(シェル)から渡される環境変数が入っている．

  for (int i = 0; envp[i] != NULL; i++) {
    printf("%s\n", envp[i]);
  }

  return EXIT_SUCCESS;
}
