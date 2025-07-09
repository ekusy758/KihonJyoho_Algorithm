#include <stdio.h>
#include <stdint.h>

uint8_t* encode(int codePoint) {
  static uint8_t utf8Bytes[3] = {224, 128, 128}; // 1110xxxx, 10xxxxxx, 10xxxxxx 
  int cp = codePoint;
  int i;
  for (i = 2; i >= 0; i--) {
    utf8Bytes[i] = utf8Bytes[i] + (cp % 64);
    cp = cp / 64;
  }
  return utf8Bytes;
}

void printBits(uint8_t byte) {
  for (int i = 7; i >= 0; i--) {
    printf("%d", (byte >> i) & 1);
  }
}

void printUtf8Bytes(int codePoint) {
  uint8_t* bytes;
  if (codePoint >= 0x800 && codePoint <= 0xFFFF) {
    bytes = encode(codePoint);
    printf("UTF-8: ");
    for (int i = 0; i < 3; i++) {
      printBits(bytes[i]); printf(" ");
    }
  } 
}

int main() {
  printUtf8Bytes(0x3042);
  return 0;
}