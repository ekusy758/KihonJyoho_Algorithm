#include <stdio.h>

char* fizzBuzz(int num) {
  char* result = "";
  if (num % 3 == 0 && num % 5 == 0) {
    result = "3‚Æ5‚ÅŠ„‚èØ‚ê‚é";
  } else if (num % 3 == 0) {
    result = "3‚ÅŠ„‚èØ‚ê‚é";
  } else if (num % 5 == 0) {
    result = "5‚ÅŠ„‚èØ‚ê‚é";
  } else {
    result = "3‚Å‚à5‚Å‚àŠ„‚èØ‚ê‚È‚¢";
  }
  return result;
}

int main() {
  printf("%d‚Í%s\n", 15, fizzBuzz(15));
  printf("%d‚Í%s\n", 3, fizzBuzz(3));
  printf("%d‚Í%s\n", 5, fizzBuzz(5));
  printf("%d‚Í%s\n", 7, fizzBuzz(7));
  return 0;
}