#include <stdio.h>
#include <stdlib.h>

int fee(int age) {
  int ret = 0;
  if (age <= 3) {
    ret = 100;
  } else if (age <= 9) {
    ret = 300;
  } else {
    ret = 500;
  }
  return ret;
}

int main(int argc, char **argv) {
  if (argc == 2) {
    printf("age %s: %d yen.\n", argv[1], fee(atoi(argv[1])));
  }
  return 0;
}