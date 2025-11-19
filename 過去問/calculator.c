// 過去問 問１の回答??

#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[]){
//     int input_num1 = atoi(argv[1]); // 入力（数字1）
//     char input_id;
//     input_id = argv[2][0]; // 入力（記号）
//     int input_num2 = atoi(argv[3]); // 入力（数字2）

//     int ans = 0;
//     switch (input_id) {
//       case '+':
//         ans = input_num1 + input_num2;
//         break;

//       case '-':
//         ans = input_num1 - input_num2;
//         break;

//       case '*':
//         ans = input_num1 * input_num2;
//         break;

//       case '/':
//         ans = input_num1 / input_num2;
//         break;

//       }
//     printf("%d %c %d = %d\n", input_num1, input_id, input_num2, ans);

//     return 0;
// }


// 2個目
// 過去問 問１の回答??

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int input_num1 = atoi(argv[1]); // 入力（数字1）
    int input_num2 = atoi(argv[2]); // 入力（数字2）
    int input_id = atoi(argv[3]); // 入力（記号）

    int ans = 0;
    char id;
    switch (input_id) {
      case 1:
        ans = input_num1 + input_num2;
        id = '+';
        break;

      case 2:
        ans = input_num1 - input_num2;
        id = '-';
        break;

      case 3:
        ans = input_num1 * input_num2;
        id = '*';
        break;

      case 4:
        ans = input_num1 / input_num2;
        id = '/';
        break;

      }
    printf("%d %c %d = %d\n", input_num1, id, input_num2, ans);

    return 0;
}
