#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  char command[256], line[256], cmd_arg[256];
  int st;
  static char prompt[64] = "> ";
  fprintf(stderr, "%s", prompt);
  while (fgets(line, sizeof(line), stdin) != NULL) {
    // 　文字列の初期化
    for (int i = 0; i < 256; i++) {
      if (command[i] != '\0') {
        command[i] = '\0';
      } else {
        break;
      }
    }

    for (int i = 0; i < 256; i++) {
      if (cmd_arg[i] != '\0') {
        cmd_arg[i] = '\0';
      } else {
        break;
      }
    }

    if (sscanf(line, "%s %s", command, cmd_arg) > 0) {
      printf("Input command: %s %s\n\n", command, cmd_arg);
      if (fork() == 0) {
        if ((int)cmd_arg[0] == 0) {
          if (execl(command, command, NULL) < 0) {
            exit(EXIT_FAILURE);
          }
        } else {
          if (execl(command, command, cmd_arg, NULL) < 0) {
            exit(EXIT_FAILURE);
          }
        }
      } else {
        wait(&st);
      }
    }
    fprintf(stderr, "%s", prompt);
  }

  return EXIT_SUCCESS;
}
