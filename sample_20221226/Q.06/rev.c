#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void printBinary(uint8_t num) {
  bool bits[8] = {0}; // 0 or 1
  printf("    %3d: ", num);
  for (int i = 7; num > 0; i--) {
    bits[i] = num % 2;
    num = num / 2;
  }
  for (int i = 0; i < 8; i++) {
    printf("%d", bits[i]);
  }
  printf("\n");
}

uint8_t rev(uint8_t byte, int choice) {
  uint8_t rbyte = byte;
  uint8_t r = 0b00000000;
  int i = 1;
  printf("\n------ rev %d trace ------\n", choice);
  for (; i <= 8; i++) {
    switch(choice) {
      case 1:
        r = ((r << 1) | (rbyte & 0b00000001));
        rbyte = rbyte >> 1;
        break;
      case 2:
        r = ((r << 7) | (rbyte & 0b00000001));
        rbyte = rbyte >> 7;
        break;
      case 3:
        r = (rbyte << 1) | (rbyte >> 7);
        rbyte = r;
        break;
      case 4:
        r = (rbyte >> 1) | (rbyte << 7);
        rbyte = r;
        break;
      default:
        break;
    }
    printf("<Loop %d>\n", i); printBinary(r); printBinary(rbyte);
  }
  return r;
}

int main() {
  // 75: 01001011 210: 11010010
  int ret1 = rev(75, 1);
  int ret2 = rev(75, 2);
  int ret3 = rev(75, 3);
  int ret4 = rev(75, 4);
  return 0;
}
