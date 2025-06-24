#include <stdio.h>

char* fizzBuzz(int num) {
  char* result = "";
  if (num % 3 == 0 && num % 5 == 0) {
    result = "3��5�Ŋ���؂��";
  } else if (num % 3 == 0) {
    result = "3�Ŋ���؂��";
  } else if (num % 5 == 0) {
    result = "5�Ŋ���؂��";
  } else {
    result = "3�ł�5�ł�����؂�Ȃ�";
  }
  return result;
}

int main() {
  printf("%d��%s\n", 15, fizzBuzz(15));
  printf("%d��%s\n", 3, fizzBuzz(3));
  printf("%d��%s\n", 5, fizzBuzz(5));
  printf("%d��%s\n", 7, fizzBuzz(7));
  return 0;
}