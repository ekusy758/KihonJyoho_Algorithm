#include <stdio.h>

int gcd(int num1, int num2) {
  int x = num1;
  int y = num2;
  while (x != y) {
    if (x > y) {
      x = x - y;
    } else {
      y = y - x;
    }
  }
  return x;
}

int main() {
  printf("%d‚Æ%d‚ÌÅ‘åŒö–ñ”‚ÍA%d‚Å‚·.\n", 18, 12, gcd(18, 12));
  printf("%d‚Æ%d‚ÌÅ‘åŒö–ñ”‚ÍA%d‚Å‚·.\n", 12, 18, gcd(12, 18));
  return 0;
}