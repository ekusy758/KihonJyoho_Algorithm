#include <stdio.h>

int main() {
  int x = 1;
  int y = 2;
  int z = 3;
  x = y;
  y = z;
  z = x;
  printf("%d,%d\n", y, z);
  return 0;
}