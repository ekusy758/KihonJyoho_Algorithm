#include <stdio.h>

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int right, left;
  int tmp;
  size_t length = sizeof(array) / sizeof(array[0]);

  for (left = 0; left < (length / 2); left++) {
    right = length - left - 1;
    tmp = array[right];
    array[right] = array[left];
    array[left] = tmp;
  }

  printf("Reversed array: {");
  for (int i = 0; i < length; i++) {
    printf("%d", array[i]);
    if (i < length - 1) printf(", ");
  }
  printf("}\n");

  return 0;
}