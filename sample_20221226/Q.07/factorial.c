#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  printf("%d * factorial(%d)\n", n, n - 1); // Check factorial status!
  return n * factorial(n - 1);
}

int main() {
  printf("factorial(5) = %d\n", factorial(5));
  return 0;
}
