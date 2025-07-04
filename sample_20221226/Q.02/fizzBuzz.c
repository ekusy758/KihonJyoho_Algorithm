#include <stdio.h>

char* fizzBuzz(int num) {
  char* result = "";
  if (num % 3 == 0 && num % 5 == 0) {
    result = "3と5で割り切れる";
  } else if (num % 3 == 0) {
    result = "3で割り切れる";
  } else if (num % 5 == 0) {
    result = "5で割り切れる";
  } else {
    result = "3でも5でも割り切れない";
  }
  return result;
}

int main() {
  printf("%dは%s\n", 15, fizzBuzz(15));
  printf("%dは%s\n", 3, fizzBuzz(3));
  printf("%dは%s\n", 5, fizzBuzz(5));
  printf("%dは%s\n", 7, fizzBuzz(7));
  return 0;
}