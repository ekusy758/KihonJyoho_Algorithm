#include <stdio.h>
#include <stdint.h>

void printBits(uint8_t byte);

uint8_t rev(uint8_t byte) {
  uint8_t rbyte = byte;
  uint8_t r = 0b00000000;
  int i;
  for (i = 0; i < 8; i++) {
    r = ((r << 1) | (rbyte & 0b00000001));
    rbyte = rbyte >> 1;
    printf("TRACE(%d) r = ", i + 1); printBits(r); // ビット状態を出力
  }
  return r;
}

void printBits(uint8_t byte) {
  for (int i = 7; i >= 0; i--) {
    printf("%d", (byte >> i) & 1);
  }
  printf("\n");
}

int main() {
  uint8_t revBits = rev(0b01001011);
  printf("rev(01001011) = "); printBits(revBits);
  return 0;
}
