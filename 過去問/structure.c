// 問題2

#include <stdio.h>
#include <string.h>

typedef struct {
  int num;
  char name[256];
  float height;
  float weight;
} CARD;

int main() {
  CARD card[40];
  strcpy(card[0].name, "daichi");
  card[0].num = 0;
  card[0].height = 167.0;
  card[0].weight = 53.0;

  printf("%s: %d %fcm %fkg", card[0].name, card[0].num, card[0].height, card[0].weight);

  return 0;
}
