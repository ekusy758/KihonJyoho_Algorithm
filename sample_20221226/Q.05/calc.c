#include <stdio.h>
#include <math.h>

double calc(double x, double y) {
  return pow(pow(x, 2) + pow(y, 2), 0.5);
}

int main() {
  printf("calc(%.1f, %.1f) = %.1f", 3.0, 4.0, calc(3.0, 4.0));
  return 0;
}